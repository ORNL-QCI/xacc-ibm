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
#include "IBMAccelerator.hpp"

#include "GateQIR.hpp"
#include "XACC.hpp"

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

namespace xacc {
namespace quantum {

std::shared_ptr<AcceleratorBuffer> IBMAccelerator::createBuffer(
			const std::string& varId) {
	if (!isValidBufferSize(30)) {
		XACCError("Invalid buffer size.");
	}

	std::shared_ptr<AcceleratorBuffer> buffer = std::make_shared<AcceleratorBuffer>(varId, 30);

	storeBuffer(varId, buffer);
	return buffer;

}

std::shared_ptr<AcceleratorBuffer> IBMAccelerator::createBuffer(
		const std::string& varId, const int size) {
	if (!isValidBufferSize(size)) {
		XACCError("Invalid buffer size.");
	}

	std::shared_ptr<AcceleratorBuffer> buffer = std::make_shared<AcceleratorBuffer>(varId, size);
	storeBuffer(varId, buffer);
	return buffer;
}

bool IBMAccelerator::isValidBufferSize(const int NBits) {
	return NBits > 0 && NBits < 31;
}

std::vector<std::shared_ptr<IRTransformation>> IBMAccelerator::getIRTransformations() {

	std::vector<std::shared_ptr<IRTransformation>> transformations;

	std::string backendName = "ibmqx_qasm_simulator";

	if (xacc::optionExists("ibm-backend")) {
		backendName = xacc::getOption("ibm-backend");
	}

	if (!availableBackends.count(backendName)) {
		XACCError(backendName + " is not available.");
	}

	auto backend = availableBackends[backendName];

	if (!backend.couplers.empty()) {
		auto transform = std::make_shared<IBMIRTransformation>(
				backend.couplers);
		transformations.push_back(transform);
	}
	return transformations;
}

void IBMAccelerator::initialize() {
	std::string jsonStr = "", apiKey = "";
	auto options = RuntimeOptions::instance();
	searchAPIKey(apiKey, url);
	std::string tokenParam = "apiToken=" + apiKey;

	std::map<std::string, std::string> headers { { "Content-Type",
			"application/x-www-form-urlencoded" },
			{ "Connection", "keep-alive" }, { "Content-Length", std::to_string(
					tokenParam.length()) } };

	auto response = restClient->post(url, "/api/users/loginWithToken", tokenParam, headers);

	if (boost::contains(response, "error")) {
		XACCError("Error received from IBM\n" + response);
	}

	Document d;
	d.Parse(response);
	currentApiToken = d["id"].GetString();

	response = restClient->get(url, "/api/Backends?access_token="+currentApiToken);

	d.Parse(response);

	for (auto& b : d.GetArray()) {

		IBMBackend backend;
		if (b.HasMember("nQubits")) {
			backend.nQubits = b["nQubits"].GetInt();
		}
		backend.name = b["name"].GetString();
		backend.description = b["description"].GetString();
		backend.status = !boost::contains(b["status"].GetString(),"off");

		backend.isSimulator = b["simulator"].GetBool();
		if (!backend.isSimulator && b.HasMember("couplingMap")) {
			auto couplers = b["couplingMap"].GetArray();
			for (int j = 0; j < couplers.Size(); j++) {
				backend.couplers.push_back(
						std::make_pair(couplers[j][0].GetInt(),
								couplers[j][1].GetInt()));
			}
		}

		availableBackends.insert(std::make_pair(backend.name, backend));
	}

	// Set these for RemoteAccelerator.execute
	postPath = "/api/Jobs?access_token="+currentApiToken;
	remoteUrl = url;
}

/**
 * take ir, generate json post string
 */
const std::string IBMAccelerator::processInput(
		std::shared_ptr<AcceleratorBuffer> buffer,
		std::vector<std::shared_ptr<Function>> functions) {

	// Get the runtime options map, and initialize
	// some basic variables we are going to need
	auto options = RuntimeOptions::instance();
	std::string backendName = "ibmqx_qasm_simulator";
	std::string jsonStr = "{\"qasms\": [";
	std::string shots = "1024";
	std::map<std::string, std::string> headers;

	if (xacc::optionExists("ibm-backend")) {
		auto newBackend = xacc::getOption("ibm-backend");
		if (availableBackends.find(newBackend) == availableBackends.end()) {
			XACCError("Invalid IBM Backend string");
		}
		if (!availableBackends[newBackend].status) {
			XACCError(
					newBackend + " is currently unavailable, status = off");
		}

		backendName = newBackend;
		chosenBackend = availableBackends[backendName];
	}

	if (xacc::optionExists("ibm-shots")) {
		shots = xacc::getOption("ibm-shots");
	}

	for (auto kernel : functions) {
		// Create the Instruction Visitor that is going
		// to map our IR to Quil.
		auto visitor = std::make_shared<OpenQasmVisitor>(buffer->size());

		// Our QIR is really a tree structure
		// so create a pre-order tree traversal
		// InstructionIterator to walk it
		InstructionIterator it(kernel);
		while (it.hasNext()) {
			// Get the next node in the tree
			auto nextInst = it.next();
			if (nextInst->isEnabled())
				nextInst->accept(visitor);
		}



		auto qasmStr = visitor->getOpenQasmString();
		boost::replace_all(qasmStr, "\n", "\\n");

		jsonStr += "{\"qasm\": \"" + qasmStr + "\"},";
		std::cout << "OpenQasm:\n" << qasmStr << "\n";
	}

	jsonStr = jsonStr.substr(0, jsonStr.size()-1) + "]";
	jsonStr += ", \"shots\": "+shots+", \"maxCredits\": 5, "
			"\"backend\": {\"name\": \""+ backendName +"\"}}";

	return jsonStr;

}

/**
 * take response and create
 */
std::vector<std::shared_ptr<AcceleratorBuffer>> IBMAccelerator::processResponse(
		std::shared_ptr<AcceleratorBuffer> buffer,
		const std::string& response) {

	if (boost::contains(response, "error")) {
		std::cout << response << "\n";
	}
	Document d;
	d.Parse(response);
	std::string jobId = std::string(d["id"].GetString());

	std::string getPath = "/api/Jobs/"+jobId + "?access_token="+currentApiToken;

	std::string getResponse = restClient->get(url, getPath);

	// Loop until the job is complete,
	// get the JSON response
	std::string msg;
	bool jobCompleted = false;
	while (!jobCompleted) {

		// Execute HTTP Get
		getResponse = restClient->get(url, getPath);

		// Search the result for the status : COMPLETED indicator
		if (boost::contains(getResponse, "COMPLETED")) {
			jobCompleted = true;
		}

		Document d;
		d.Parse(getResponse);
		if (d.HasMember("infoQueue")) {
			auto info = d["infoQueue"].GetObject();
			std::cout << "\r" << "Job Response: " << d["status"].GetString()
					<< ", queue: " << d["infoQueue"]["status"].GetString();
			if (info.HasMember("position")) {
				std::cout << " position " << d["infoQueue"]["position"].GetInt()
						<< std::flush;
			}
		} else {
			std::cout << "\r" << "Job Response: " << d["status"].GetString()
					<< std::flush;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	std::cout << std::endl;

	d.Parse(getResponse);

	auto qasmsArray = d["qasms"].GetArray();
	if (qasmsArray.Size() == 1) {
		const Value& counts = qasmsArray[0]["result"]["data"]["counts"];
		for (Value::ConstMemberIterator itr = counts.MemberBegin();
				itr != counts.MemberEnd(); ++itr) {

			// NOTE THESE BITS ARE LEFT MOST IS MOST SIGNIFICANT,
			// LEFT MOST IS (N-1)th Qubit, RIGHT MOST IS 0th qubit
			std::string bitStr = itr->name.GetString();
			int nOccurrences = itr->value.GetInt();
			if (chosenBackend.isSimulator) {
				boost::replace_all(bitStr, " ", "");
			} else {
				bitStr = bitStr.substr(bitStr.length()-buffer->size(), bitStr.length());
			}
			boost::dynamic_bitset<> outcome(bitStr);
			std::stringstream xx;
			xx << outcome << " " << nOccurrences << " times";
			XACCInfo("IBM Measurement outcome: " + xx.str() +".");
			for (int i = 0; i < nOccurrences; i++) {
				buffer->appendMeasurement(outcome);
			}
		}

		// Return empty list since data is stored on the given buffer.
		return std::vector<std::shared_ptr<AcceleratorBuffer>>{};
	} else {

		std::vector<std::shared_ptr<AcceleratorBuffer>> buffers;

		for (SizeType i = 0; i < qasmsArray.Size(); i++) {

			auto tmpBuffer = createBuffer(buffer->name() + std::to_string(i),
					buffer->size());

			const Value& counts = qasmsArray[i]["result"]["data"]["counts"];
			for (Value::ConstMemberIterator itr = counts.MemberBegin();
					itr != counts.MemberEnd(); ++itr) {

				// NOTE THESE BITS ARE LEFT MOST IS MOST SIGNIFICANT,
				// LEFT MOST IS (N-1)th Qubit, RIGHT MOST IS 0th qubit
				std::string bitStr = itr->name.GetString();
				if (chosenBackend.isSimulator) {
					boost::replace_all(bitStr, " ", "");
					std::cout << "BITSTRING IS " << bitStr << "\n";
				}

				if (!chosenBackend.isSimulator) {
					if (buffer->size() < bitStr.length()) {
						bitStr = bitStr.substr(bitStr.length() - buffer->size(),
								bitStr.length());
					}
				}

				boost::dynamic_bitset<> outcome(bitStr);
				std::cout << "Result: " << outcome << ": " << itr->value.GetInt() << "\n";
				int nOccurrences = itr->value.GetInt();
				for (int i = 0; i < nOccurrences; i++) {
					tmpBuffer->appendMeasurement(outcome);
				}

			}

			buffers.push_back(tmpBuffer);
		}

		return buffers;
	}
}


std::shared_ptr<AcceleratorGraph> IBMAccelerator::getAcceleratorConnectivity() {
	std::string backendName = "ibmqx_qasm_simulator";

	if (xacc::optionExists("ibm-backend")) {
		backendName = xacc::getOption("ibm-backend");
	}

	if (!availableBackends.count(backendName)) {
		XACCError(backendName + " is not available.");
	}

	auto backend = availableBackends[backendName];
	auto graph = std::make_shared<AcceleratorGraph>(backend.nQubits);

	if (!backend.couplers.empty()) {
		for (auto es : backend.couplers) {
			graph->addEdge(es.first, es.second);
		}
	} else {
		for (int i = 0; i < backend.nQubits; i++) {
			for (int j = 0; j < backend.nQubits; j++) {
				if (i < j) {
					graph->addEdge(i, j);
				}
			}
		}
	}

	return graph;
}

void IBMAccelerator::searchAPIKey(std::string& key, std::string& url) {

	// Search for the API Key in $HOME/.dwave_config,
	// $DWAVE_CONFIG, or in the command line argument --dwave-api-key
	auto options = RuntimeOptions::instance();
	boost::filesystem::path dwaveConfig(
			std::string(getenv("HOME")) + "/.ibm_config");

	if (boost::filesystem::exists(dwaveConfig)) {
		findApiKeyInFile(key, url, dwaveConfig);
	} else if (const char * nonStandardPath = getenv("IBM_CONFIG")) {
		boost::filesystem::path nonStandardDwaveConfig(
						nonStandardPath);
		findApiKeyInFile(key, url, nonStandardDwaveConfig);
	} else {

		// Ensure that the user has provided an api-key
		if (!options->exists("ibm-api-key")) {
			XACCError("Cannot execute kernel on IBM chip without API Key.");
		}

		// Set the API Key
		key = (*options)["ibm-api-key"];

		if (options->exists("ibm-api-url")) {
			url = (*options)["ibm-api-url"];
		}
	}

	// If its still empty, then we have a problem
	if (key.empty()) {
		XACCError("Error. The API Key is empty. Please place it "
				"in your $HOME/.ibm_config file, $IBM_CONFIG env var, "
				"or provide --ibm-api-key argument.");
	}
}

void IBMAccelerator::findApiKeyInFile(std::string& apiKey, std::string& url,
		boost::filesystem::path &p) {
	std::ifstream stream(p.string());
	std::string contents(
			(std::istreambuf_iterator<char>(stream)),
			std::istreambuf_iterator<char>());

	std::vector<std::string> lines;
	boost::split(lines, contents, boost::is_any_of("\n"));
	for (auto l : lines) {
		if (boost::contains(l, "key")) {
			std::vector<std::string> split;
			boost::split(split, l, boost::is_any_of(":"));
			auto key = split[1];
			boost::trim(key);
			apiKey = key;
		} else if (boost::contains(l, "url")) {
			std::vector<std::string> split;
			boost::split(split, l, boost::is_any_of(":"));
			auto key = split[1] + ":" + split[2];
			boost::trim(key);
			url = key;
		}
	}
}
}
}
