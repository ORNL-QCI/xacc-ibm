/***********************************************************************************
 * Copyright (c) 2017, UT-Battelle
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of the xacc nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Contributors:
 *   Initial API and implementation - Alex McCaskey
 *
 **********************************************************************************/
#include "LocalIBMAccelerator.hpp"
#include "XACC.hpp"
#include "simulator.hpp"

namespace xacc {
namespace quantum {

std::shared_ptr<AcceleratorBuffer> LocalIBMAccelerator::createBuffer(
			const std::string& varId) {
	if (!isValidBufferSize(30)) {
		xacc::error("Invalid buffer size.");
	}

	std::shared_ptr<AcceleratorBuffer> buffer = std::make_shared<AcceleratorBuffer>(varId, 30);

	storeBuffer(varId, buffer);
	return buffer;

}

std::shared_ptr<AcceleratorBuffer> LocalIBMAccelerator::createBuffer(
		const std::string& varId, const int size) {
	if (!isValidBufferSize(size)) {
		xacc::error("Invalid buffer size.");
	}

	std::shared_ptr<AcceleratorBuffer> buffer = std::make_shared<
			AcceleratorBuffer>(varId, size);

	storeBuffer(varId, buffer);
	return buffer;
}

bool LocalIBMAccelerator::isValidBufferSize(const int NBits) {
	return NBits > 0 && NBits < 31;
}

std::vector<std::shared_ptr<IRTransformation>> LocalIBMAccelerator::getIRTransformations() {
	std::vector<std::shared_ptr<IRTransformation>> transformations;
	return transformations;
}

void LocalIBMAccelerator::execute(std::shared_ptr<AcceleratorBuffer> buffer,
			const std::shared_ptr<xacc::Function> kernel) {
          
}

std::vector<std::shared_ptr<AcceleratorBuffer>> LocalIBMAccelerator::execute(
			std::shared_ptr<AcceleratorBuffer> buffer,
			const std::vector<std::shared_ptr<Function>> functions) {
    std::string jsonStr = "{\"qasms\": [";
	std::string shots = "1024";
	int kernelCounter = 0;
	for (auto kernel : functions) {
		// Create the Instruction Visitor that is going
		// to map our IR to Quil.
		auto visitor = std::make_shared<OpenQasmVisitor>(buffer->size());

		// Our QIR is really a tree structure
		// so create a pre-order tree traversal
		// InstructionIterator to walk it
		InstructionIterator it(kernel);
		measurementSupports.insert(std::make_pair(kernelCounter, std::vector<int>{}));
		while (it.hasNext()) {
			// Get the next node in the tree
			auto nextInst = it.next();
			if (nextInst->isEnabled()) {
				nextInst->accept(visitor);
				if (nextInst->name() == "Measure") {
					auto qbitIdx = nextInst->bits()[0];
					measurementSupports[kernelCounter].push_back(qbitIdx);
				}
			}
		}

		auto qasmStr = visitor->getOpenQasmString();
		boost::replace_all(qasmStr, "\n", "\\n");

		jsonStr += "{\"qasm\": \"" + qasmStr + "\"},";

		kernelCounter++;
	}

	jsonStr = jsonStr.substr(0, jsonStr.size()-1) + "]";
	jsonStr += ", \"shots\": "+shots+", \"maxCredits\": 5}";

    std::string response ="";
	Document d;
	d.Parse(response);

	auto qasmsArray = d["qasms"].GetArray();
	if (qasmsArray.Size() == 1) {
		const Value& counts = qasmsArray[0]["result"]["data"]["counts"];
		for (Value::ConstMemberIterator itr = counts.MemberBegin();
				itr != counts.MemberEnd(); ++itr) {

			// NOTE THESE BITS ARE LEFT MOST IS MOST SIGNIFICANT,
			// LEFT MOST IS (N-1)th Qubit, RIGHT MOST IS 0th qubit
			std::string bitStr = itr->name.GetString();
			int nOccurrences = itr->value.GetInt();
			boost::replace_all(bitStr, " ", "");
			boost::dynamic_bitset<> outcome(bitStr);
			std::stringstream xx;
			xx << outcome << " " << nOccurrences << " times";
			xacc::info("IBM Measurement outcome: " + xx.str() +".");
			for (int i = 0; i < nOccurrences; i++) {
				buffer->appendMeasurement(outcome);
			}
		}

		measurementSupports.clear();
		// Return empty list since data is stored on the given buffer.
		return std::vector<std::shared_ptr<AcceleratorBuffer>>{};
	} else {

		std::vector<std::shared_ptr<AcceleratorBuffer>> buffers;

		for (SizeType i = 0; i < qasmsArray.Size(); i++) {

			xacc::info("--------------------------");
			xacc::info("Kernel " + std::to_string(i));
			std::stringstream sss;
			for (auto q : measurementSupports[i]) {
				sss << q << ", ";
			}
			xacc::info("Measured Qubits: " + sss.str());

			auto tmpBuffer = createBuffer(buffer->name() + std::to_string(i),
					buffer->size());

			const Value& counts = qasmsArray[i]["result"]["data"]["counts"];
			for (Value::ConstMemberIterator itr = counts.MemberBegin();
					itr != counts.MemberEnd(); ++itr) {

				// NOTE THESE BITS ARE LEFT MOST IS MOST SIGNIFICANT,
				// LEFT MOST IS (N-1)th Qubit, RIGHT MOST IS 0th qubit
				std::string bitStr = itr->name.GetString();
				int nOccurrences = itr->value.GetInt();

				boost::replace_all(bitStr, " ", "");

				xacc::info("IBM Results: " + std::string(bitStr) + ":" + std::to_string(nOccurrences));

					if (buffer->size() < bitStr.length()) {
						bitStr = bitStr.substr(bitStr.length() - buffer->size(),
								bitStr.length());
					}

					// Turn off measure results that didn't have
					// a requested measurement gate, otherwise our
					// expectation values will be skewed.
					auto supportedQbits = measurementSupports[i];
					int counter = 0;
					for (int i = bitStr.length()-1; i >= 0; i--) {
						if (std::find(supportedQbits.begin(), supportedQbits.end(), counter) == supportedQbits.end()) {
							bitStr[i] = '0';
						}
						counter++;
					}

				xacc::info("Our Results: " + std::string(bitStr) + ":" + std::to_string(itr->value.GetInt()));

				boost::dynamic_bitset<> outcome(bitStr);
				for (int i = 0; i < nOccurrences; i++) {
					tmpBuffer->appendMeasurement(outcome);
				}
			}

			xacc::info("--------------------------");

			buffers.push_back(tmpBuffer);
		}

		measurementSupports.clear();
		return buffers;
	}
}
}
}
