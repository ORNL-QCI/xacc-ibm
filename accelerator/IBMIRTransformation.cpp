#include "IBMIRTransformation.hpp"
#include "XACC.hpp"

namespace xacc {
namespace quantum {

std::shared_ptr<IR> IBMIRTransformation::transform(std::shared_ptr<IR> ir) {

	xacc::info("Executing IBM IR Transformation - Modifying CNOT connectivity.");

	auto newir = std::make_shared<GateQIR>();

	for (auto kernel : ir->getKernels()) {

//		std::cout << "KERNEL BEFORE:\n" << kernel->toString("qreg") << "\n\n";
		currentKernelInstructionIdx = 0;

		InstructionIterator it(kernel);
		while (it.hasNext()) {
			// Get the next node in the tree
			auto nextInst = it.next();

			if (!nextInst->isComposite() && nextInst->isEnabled()) {
				nextInst->accept(this);

				if (!nextInst->isEnabled() && "CNOT" == nextInst->getName()) {
					kernel->removeInstruction(currentKernelInstructionIdx);
					int count = 0;
					for (auto inst : newInstructions) {
						kernel->insertInstruction(
								currentKernelInstructionIdx + count, inst);
						count++;
					}

					currentKernelInstructionIdx += count - 1;
				}

				newInstructions.clear();
				currentKernelInstructionIdx++;
			}

		}

//		std::cout << "KERNEL AFTER:\n" << kernel->toString("qreg") << "\n";

		newir->addKernel(kernel);
	}


	return newir;
}

void IBMIRTransformation::visit(CNOT& cnot) {

	auto source = cnot.bits()[0];
	auto target = cnot.bits()[1];

	if (!isCouplingAvailable(source, target)) {

		auto gateRegistry = GateInstructionRegistry::instance();

		// Disable this cnot
		cnot.disable();

		// Here I know that this cnot is at
		// the currentKernelInstructionIdx, so I want
		// to insert 2 Hadamards, a reversed cnot, then 2 hadamards

		auto h0 = gateRegistry->create("H", std::vector<int> { source });
		auto h1 = gateRegistry->create("H", std::vector<int> { target });
		auto revCnot = gateRegistry->create("CNOT", std::vector<int> { target,
				source });

		newInstructions.push_back(h0);
		newInstructions.push_back(h1);
		newInstructions.push_back(revCnot);
		newInstructions.push_back(h0);
		newInstructions.push_back(h1);
	}
}

bool IBMIRTransformation::isCouplingAvailable(const int src, const int tgt) {
	for (auto c : _couplers) {
		if (c.first == src && c.second == tgt) {
			return true;
		}
	}
	return false; //tgt == _couplers[src].first || tgt == _couplers[src].second;
}

}
}
