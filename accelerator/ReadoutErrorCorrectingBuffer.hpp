/*
 * ReadoutErrorCorrectingBuffer.hpp
 *
 *  Created on: Nov 8, 2017
 *      Author: aqw
 */

#ifndef ACCELERATOR_READOUTERRORCORRECTINGBUFFER_HPP_
#define ACCELERATOR_READOUTERRORCORRECTINGBUFFER_HPP_


#include "AcceleratorBuffer.hpp"

namespace xacc {
namespace quantum {
class ReadoutCorrectingBufer: public xacc::AcceleratorBuffer {

protected:

	std::vector<std::pair<double,double>> etas;

public:
	/**
	 * The Constructor
	 */
	ReadoutCorrectingBufer(const std::string& str, const int N) :
			AcceleratorBuffer(str, N) {
		for (int i = 0; i < N; i++) etas.push_back({0.5,0.5});
	}

	ReadoutCorrectingBufer(const std::string& str, const int N,
			std::vector<std::pair<double, double>> es) :
			AcceleratorBuffer(str, N), etas(es) {
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
	ReadoutCorrectingBufer(const std::string& str, int firstIndex,
			Indices ... indices) :
			bufferId(str), nBits(1 + sizeof...(indices)) {
	}

	/**
	 * The copy constructor
	 */
	ReadoutCorrectingBufer(const ReadoutCorrectingBufer& other) :
			AcceleratorBuffer(other), etas(other.etas) {
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


		return val;
	}

};
}
}
#endif
