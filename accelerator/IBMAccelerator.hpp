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
#ifndef QUANTUM_GATE_ACCELERATORS_IBMACCELERATOR_HPP_
#define QUANTUM_GATE_ACCELERATORS_IBMACCELERATOR_HPP_

#include "RemoteAccelerator.hpp"
#include "InstructionIterator.hpp"
#include "RuntimeOptions.hpp"
#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include "OpenQasmVisitor.hpp"
#include "IBMIRTransformation.hpp"

#include <Eigen/Core>
#define RAPIDJSON_HAS_STDSTRING 1

#include "rapidjson/prettywriter.h"
#include "rapidjson/document.h"

using namespace rapidjson;

using namespace xacc;

namespace xacc {
namespace quantum {



/**
 * Wrapper for information related to the remote
 * D-Wave solver.
 */
struct IBMBackend {
	std::string name;
	std::string description;
	int nQubits;
	std::vector<std::pair<int,int>> couplers;
	bool status = true;
	bool isSimulator = true;
};

/**
 * The IBMAccelerator is a QPUGate Accelerator that
 * provides an execute implementation that maps XACC IR
 * to an equivalent Quil string, and executes it on the
 * IBM superconducting quantum chip at api.IBM.com/qvm
 * through Fire's HTTP Client utilities.
 *
 */
class IBMAccelerator : public RemoteAccelerator {
public:

	/**
	 * Create, store, and return an AcceleratorBuffer with the given
	 * variable id string and of the given number of bits.
	 * The string id serves as a unique identifier
	 * for future lookups and reuse of the AcceleratorBuffer.
	 *
	 * @param varId
	 * @param size
	 * @return
	 */
	std::shared_ptr<AcceleratorBuffer> createBuffer(const std::string& varId,
			const int size);

	/**
	 * Create, store, and return an AcceleratorBuffer with the given
	 * variable id string. This method returns all available
	 * qubits for this Accelerator. The string id serves as a unique identifier
	 * for future lookups and reuse of the AcceleratorBuffer.
	 *
	 * @param varId The variable name of the created buffer
	 * @return buffer The buffer instance created.
	 */
	virtual std::shared_ptr<AcceleratorBuffer> createBuffer(
				const std::string& varId);

	/**
	 * Initialize this Accelerator. This method is called
	 * by the XACC framework after an Accelerator has been
	 * requested and created. Perform any work you need
	 * done before execution here.
	 *
	 */
	virtual void initialize();

	/**
	 * Return the graph structure for this Accelerator.
	 *
	 * @return connectivityGraph The graph structure of this Accelerator
	 */
	virtual std::shared_ptr<AcceleratorGraph> getAcceleratorConnectivity();

	/**
	 * Return true if this Accelerator can allocated
	 * NBits number of bits.
	 * @param NBits
	 * @return
	 */
	virtual bool isValidBufferSize(const int NBits);

	/**
	 * This Accelerator models QPU Gate accelerators.
	 * @return
	 */
	virtual AcceleratorType getType() {
		return AcceleratorType::qpu_gate;
	}

	/**
	 * We have no need to transform the IR for this Accelerator,
	 * so return an empty list, for now.
	 * @return
	 */
	virtual std::vector<std::shared_ptr<IRTransformation>> getIRTransformations();

	/**
	 * Return all relevant IBMAccelerator runtime options.
	 * Users can set the api-key, execution type, and number of triels
	 * from the command line with these options.
	 */
	virtual std::shared_ptr<options_description> getOptions() {
		auto desc = std::make_shared<options_description>(
				"New IBM Accelerator Options");
		desc->add_options()("ibm-api-key", value<std::string>(),
				"Provide the IBM API key. This is used if $HOME/.ibm_config is not found")("ibm-backend",
				value<std::string>(),
				"Provide the backend name.")
				("ibm-shots", value<std::string>(), "Provide the number of shots to execute.")
				("ibm-list-backends", "List the available backends at the IBM Quantum Experience URL.")
				("ibm-api-url", "")("ibm-write-openqasm", "");

		return desc;
	}

	/**
	 * Given user-input command line options, perform
	 * some operation. Returns true if runtime should exit,
	 * false otherwise.
	 *
	 * @param map The mapping of options to values
	 * @return exit True if exit, false otherwise
	 */
	virtual bool handleOptions(variables_map& map) {
		if (map.count("ibm-list-backends")) {
			initialize();
			for (auto s : availableBackends) {
				XACCInfo("Available New IBM Backend: " +
						std::string(s.first) + " [" +
						(s.second.status ? "on" : "off")
						+ "]");
			}
			return true;
		}
		return false;
	}

	/**
	 * Return the name of this instance.
	 *
	 * @return name The string name
	 */
	virtual const std::string name() const {
		return "ibm";
	}

	/**
	 * Return the description of this instance
	 * @return description The description of this object.
	 */
	virtual const std::string description() const {
		return "The IBM Accelerator interacts with the remote IBM "
				"Quantum Experience to launch XACC quantum kernels.";
	}

	/**
	 * take ir, generate json post string
	 */
	virtual const std::string processInput(
			std::shared_ptr<AcceleratorBuffer> buffer,
			std::vector<std::shared_ptr<Function>> functions);

	/**
	 * take response and create
	 */
	virtual std::vector<std::shared_ptr<AcceleratorBuffer>> processResponse(
			std::shared_ptr<AcceleratorBuffer> buffer,
			const std::string& response);

	IBMAccelerator() :RemoteAccelerator() {}

	IBMAccelerator(std::shared_ptr<RestClient> client) : RemoteAccelerator(client) {}

	virtual bool isPhysical();

	/**
	 * The destructor
	 */
	virtual ~IBMAccelerator() {}

private:

	void computeMeasurementAccuracy(std::shared_ptr<AcceleratorBuffer> buffer);

	bool computedMeasurementAccuracy = false;

	/**
	 * Private utility to search for the IBM
	 * API key in $HOME/.pyquil_config, $PYQUIL_CONFIG,
	 * or --api-key command line arg
	 */
	void searchAPIKey(std::string& key, std::string& url);

	/**
	 * Private utility to search for key in the config
	 * file.
	 */
	void findApiKeyInFile(std::string& key, std::string& url, boost::filesystem::path &p);

	/**
	 * Reference to the temporary API Token for
	 * this IBM Quantum Experience session.
	 */
	std::string currentApiToken;

	/**
	 * The IBM Quantum Experience URL
	 */
	std::string url;

	/**
	 * Mapping of available backend name to an actual
	 * IBMBackend struct data structure.
	 */
	std::map<std::string, IBMBackend> availableBackends;

	std::map<int, std::vector<int>> measurementSupports;

	IBMBackend chosenBackend;

};

}
}




#endif
