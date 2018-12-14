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
#ifndef QUANTUM_GATE_ACCELERATORS_OpenQasmVISITOR_HPP_
#define QUANTUM_GATE_ACCELERATORS_OpenQasmVISITOR_HPP_

#include <memory>
#include "AllGateVisitor.hpp"
#include <boost/math/constants/constants.hpp>

namespace xacc {
namespace quantum {

/**
 * The OpenQasmVisitor is an InstructionVisitor that visits
 * quantum gate instructions and creates an equivalent
 * OpenQasm string that can be executed by the Rigetti
 * superconducting quantum computer.
 *
 */
class OpenQasmVisitor: public OpenQasmVisitor {
protected:

	constexpr static double pi = boost::math::constants::pi<double>();

	/**
	 * Reference to the OpenQasm string
	 * this visitor is trying to construct
	 */
	std::string OpenQasmStr;

	/**
	 * Reference to the classical memory address indices
	 * where measurements are recorded.
	 */
	std::string classicalAddresses;

	std::map<int, int> qubitToClassicalBitIndex;

	int numAddresses = 0;

	int _nQubits;


    std::string operationsJsonStr = "[";

public:

	virtual const std::string name() const {
		return "openqasm-visitor";
	}

	virtual const std::string description() const {
		return "Map XACC IR to OpenQasm.";
	}

	OpenQasmVisitor() : OpenQasmVisitor(16) {
	}

	OpenQasmVisitor(const int nQubits, bool skipPreamble = false) : _nQubits(nQubits) {
		// Create a qubit registry
		if (!skipPreamble) {
			OpenQasmStr += "\ninclude \\\"qelib1.inc\\\";\nqreg q[" + std::to_string(nQubits) + "];\n";
		}
	}

	virtual const std::string toString() {
		return getOpenQasmString();
	}

	/**
	 * Visit Analog gates
	 */
	// TODO DEFINE FOR Analog
	void visit(Analog& a) {
		std::stringstream ss, js;
		ss << "u2(" << 0 << ", " << pi << ") q[" << a.qubits()[0] << "];\n";
		OpenQasmStr += ss.str();
        js << "{\"name\":\"u2\",\"params\": [0.0," << pi << "],\"qubits\":[" << h.bits()[0]<<"]},";
        operationsJsonStr += js.str();
	}

	/**
	 * Return the OpenQasm string
	 */
	std::string getOpenQasmString() {
		return OpenQasmStr;
	}

    std::string getOperationsJsonString() {
        return operationsJsonStr.substr(0,operationsJsonStr.length()-1)+"]";
    }

	/**
	 * Return the classical measurement indices
	 * as a json int array represented as a string.
	 */
	std::string getClassicalAddresses() {
		auto retStr = classicalAddresses.substr(0, classicalAddresses.size() - 2);
		return "[" + retStr + "]";
	}

	int getNumberOfAddresses() {
		return classicalBitCounter-1;
	}
	/**
	 * The destructor
	 */
	virtual ~OpenQasmVisitor() {}
};


}
}

#endif
