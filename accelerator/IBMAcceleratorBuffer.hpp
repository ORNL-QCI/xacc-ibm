/*
 * ReadoutErrorCorrectingBuffer.hpp
 *
 *  Created on: Nov 8, 2017
 *      Author: aqw
 */

#ifndef ACCELERATOR_IBMACCELERATORBUFFER_HPP_
#define ACCELERATOR_IBMACCELERATORBUFFER_HPP_


#include "AcceleratorBuffer.hpp"

namespace xacc {
namespace quantum {
class IBMAcceleratorBuffer: public xacc::AcceleratorBuffer {

public:
	/**
	 * The Constructor
	 */
	IBMAcceleratorBuffer(const std::string& str, const int N) :
			AcceleratorBuffer(str, N) {
	}

	/**
	 * The Constructor, takes as input the name of this buffer,
	 * and the bit indices to model.
	 *
	 * @param str The name of the buffer
	 * @param firstIndex The first bit index
	 * @param indices The remaining bit indices
	 */
	template<typename ... Indices>
	IBMAcceleratorBuffer(const std::string& str, int firstIndex,
			Indices ... indices) : AcceleratorBuffer(str, firstIndex, indices...) {
	}

	/**
	 * Print information about this AcceleratorBuffer to the
	 * given output stream.
	 *
	 * @param stream Stream to write the buffer to.
	 */
	virtual void print(std::ostream& stream) {
		stream << "expectation: " << getExpectationValueZ() << "\n";
		for (auto& kv : bitStringToCounts) {
			stream << "measure result: " << kv.first << ", " << kv.second << "\n";
		}
		return;
	}

	/**
	 * Compute and return the expectation value with respect
	 * to the Pauli-Z operator. Here we provide a base implementation
	 * based on an ensemble of measurement results. Subclasses
	 * are free to implement this as they see fit, ie, for simulators
	 * use the wavefunction.
	 *
	 * @return expVal The expectation value
	 */
	virtual const double getExpectationValueZ() {
		auto val = AcceleratorBuffer::getExpectationValueZ();

		if (xacc::optionExists("ibm-rescale-expectation-values")) {
			auto data = xacc::getOption("ibm-rescale-expectation-values");

			XACCInfo("Current Expectation Value: " + std::to_string(val));
			XACCInfo("Computing Rescaled Exp Val: " + data);
			std::vector<std::string> split;
			boost::split(split, data, boost::is_any_of(","));
			auto p01 = std::stod(split[0]);
			auto p10 = std::stod(split[1]);

			XACCInfo("Probs: " + split[0] + ", " + split[1]);

			double pPlus = p01 + p10;
			double pMinus = p01 - p10;

			XACCInfo("P+-: " + std::to_string(pPlus) + ", " + std::to_string(pMinus));

//			val = (val + pPlus) / (1.0-pMinus);

			val = (val - pMinus) / (1.0 - pPlus);

			XACCInfo("New Expectation Value: " + std::to_string(val));
		}

		return val;
	}

};
}
}
#endif
