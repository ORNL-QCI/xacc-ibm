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
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE IBMAcceleratorTester

#include <memory>
#include <boost/test/included/unit_test.hpp>
#include "IBMAccelerator.hpp"
#include "xacc-ibm-config.hpp"

using namespace xacc::quantum;

/**
 * Needs to respond to initialize post /api/users/loginWithToken
 * initialize get /api/Backends?access_token=token
 * post to /api/Jobs?access_token=token
 * get /api/Jobs/" + jobId + "?access_token=token with COMPLETED message
 */
class FakeRestClient : public RestClient {

protected:

	std::string fakeInitLogin;
	std::string fakeInitGetBackends;
	std::string fakePostJob;
	std::string fakeGetResults;

public:

	FakeRestClient(const std::string& login, const std::string& initBackends,
			const std::string& post, const std::string& results) :
			fakeInitLogin(login), fakeInitGetBackends(initBackends), fakePostJob(
					post), fakeGetResults(results) {
	}

	virtual const std::string post(const std::string& remoteUrl,
				const std::string& path, const std::string& postStr,
				std::map<std::string, std::string> headers = std::map<std::string,
						std::string> { }) {
		if (path == "/api/users/loginWithToken") {
			return fakeInitLogin;
		} else {
			return fakePostJob;
		}
	}


	virtual const std::string get(const std::string& remoteUrl,
			const std::string& path) {

		if (boost::contains(path, "/api/Backends")) {
			return fakeInitGetBackends;
		} else {
			return fakeGetResults;
		}
	}
};

const std::string fakeLogin = R"fakeLogin({"id":"oRpEgRr0Su96EwLn00aM7JPQnAA49xi7XRDJEi6ObWMXCrywZ1axXq00Bh85mcDA","ttl":1209600,"created":"2017-10-04T16:49:00.645Z","userId":"12074c90bb6425be346c55a1f1318a03"})fakeLogin";
const std::string fakeBackends = R"fakeBackends([{"couplingMap":[[0,1],[0,2],[1,2],[3,2],[3,4],[4,2]],"description":"Device Real5Qv1","id":"cc7f910ff2e6860e0d4918e9ee0ebae0","nQubits":5,"name":"Device Real5Qv1","serialNumber":"Real5Qv1","simulator":false,"status":"off","topologyId":"250e969c6b9e68aa2a045ffbceb3ac33"},{"basisGates":"SU2+CNOT","chipName":"Raven","couplingMap":[[1,0],[2,0],[2,1],[2,4],[3,2],[3,4]],"description":"5 qubit transmon bowtie chip 3","id":"c16c5ddebbf8922a7e2a0f5a89cac478","nQubits":5,"name":"ibmqx4","onlineDate":"2017-09-18T11:00:00.000Z","serialNumber":"ibmqx4","simulator":false,"status":"on","topologyId":"3b8e671a5a3b56899e6e601e6a3816a1","url":"https://ibm.biz/qiskit-ibmqx4","version":"1"},{"basisGates":"u1,u2,u3,cx,id","chipName":"Sparrow","couplingMap":[[0,1],[0,2],[1,2],[3,2],[3,4],[4,2]],"description":"5 transmon bowtie","id":"28147a578bdc88ec8087af46ede526e1","nQubits":5,"name":"ibmqx2","onlineDate":"2017-01-10T12:00:00.000Z","serialNumber":"Real5Qv2","simulator":false,"status":"on","topologyId":"250e969c6b9e68aa2a045ffbceb3ac33","url":"https://ibm.biz/qiskit-ibmqx2","version":"1"},{"basisGates":"u1,u2,u3,cx,id","chipName":"Albatross","couplingMap":[[1,0],[1,2],[2,3],[3,4],[3,14],[5,4],[6,5],[6,7],[6,11],[7,10],[8,7],[9,8],[9,10],[11,10],[12,5],[12,11],[12,13],[13,4],[13,14],[15,0],[15,2],[15,14]],"description":"16 transmon 2x8 ladder","id":"f451527ae7b9c9998e7addf1067c0df4","nQubits":16,"name":"ibmqx5","onlineDate":"2017-09-21T11:00:00.000Z","serialNumber":"ibmqx5","simulator":false,"status":"on","topologyId":"ad8b182a0653f51dfbd5d66c33fd08c7","url":"https://ibm.biz/qiskit-ibmqx5","version":"1"},{"basisGates":"u1,u2,u3,cx,id","chipName":"Albatross","couplingMap":[[0,1],[1,2],[2,3],[3,14],[4,3],[4,5],[6,7],[6,11],[7,10],[8,7],[9,8],[9,10],[11,10],[12,5],[12,11],[12,13],[13,4],[13,14],[15,0],[15,14]],"description":"16 transmon 2x8 ladder","id":"2bcc3cdb587d1bef305ac14447b9b0a6","nQubits":16,"name":"ibmqx3","onlineDate":"2017-06-06T11:00:00.000Z","serialNumber":"ibmqx3","simulator":false,"status":"off","topologyId":"db99eef232f426b45d2d147359580bc6","url":"https://ibm.biz/qiskit-ibmqx3","version":"1"},{"description":"online qasm simulator","gateSet":"u1,u2,u3,cx","id":"0a403248d95598fef21ee1a71d5db79a","nQubits":24,"name":"ibmqx_qasm_simulator","serialNumber":"ibmqx_qasm_simulator","simulator":true,"status":"on","topologyId":"4cfbd99fee9fc80b91888e8c914666a5"}])fakeBackends";
const std::string fakePostResultSim = R"fakePostResults({"qasms":[{"qasm":"\ninclude \"qelib1.inc\";\nqreg q[3];\nx q[0];\nh q[1];\ncx q[1], q[2];\ncx q[0], q[1];\nh q[0];\ncreg c0[1];\nmeasure q[0] -> c0[0];\ncreg c1[1];\nmeasure q[1] -> c1[0];\nif (c0 == 1) z q[2];\nif (c1 == 1) x q[2];\ncreg c2[1];\nmeasure q[2] -> c2[0];\n","status":"WORKING_IN_PROGRESS","executionId":"a66ff99b6e44a916ed3a6c7579ee0f06"}],"shots":1024,"backend":{"name":"ibmqx_qasm_simulator"},"status":"RUNNING","maxCredits":3,"usedCredits":0,"creationDate":"2017-10-04T16:49:02.376Z","deleted":false,"id":"fd386cfd16b707b6f5d8ece36d6f7c3b","userId":"12074c90bb6425be346c55a1f1318a03"})fakePostResults";
const std::string fakeGetResultsSim = R"fakeGetResults({"backend":{"name":"ibmqx_qasm_simulator"},"calibration":{},"creationDate":"2017-10-04T16:49:02.376Z","deleted":false,"id":"fd386cfd16b707b6f5d8ece36d6f7c3b","maxCredits":3,"qasms":[{"executionId":"a66ff99b6e44a916ed3a6c7579ee0f06","qasm":"\ninclude \"qelib1.inc\";\nqreg q[3];\nx q[0];\nh q[1];\ncx q[1], q[2];\ncx q[0], q[1];\nh q[0];\ncreg c0[1];\nmeasure q[0] -> c0[0];\ncreg c1[1];\nmeasure q[1] -> c1[0];\nif (c0 == 1) z q[2];\nif (c1 == 1) x q[2];\ncreg c2[1];\nmeasure q[2] -> c2[0];\n","result":{"data":{"additionalData":{"seed":2842128583},"counts":{"1 0 0":263,"1 0 1":267,"1 1 0":241,"1 1 1":253},"creg_labels":"c2[1] c1[1] c0[1]","time":0.042070099999999999},"date":"2017-10-04T16:49:02.809Z"},"status":"DONE"}],"shots":1024,"status":"COMPLETED","usedCredits":0,"userId":"12074c90bb6425be346c55a1f1318a03"})fakeGetResults";

BOOST_AUTO_TEST_CASE(checkKernelSimExecution) {

	auto fakeClient = std::make_shared<FakeRestClient>(fakeLogin, fakeBackends,
			fakePostResultSim, fakeGetResultsSim);

	IBMAccelerator acc(fakeClient);
	acc.initialize();
	auto buffer = acc.createBuffer("qubits", 3);

	auto f = std::make_shared<GateFunction>("foo");

	auto x = std::make_shared<X>(0);
	auto h = std::make_shared<Hadamard>(1);
	auto cn1 = std::make_shared<CNOT>(1, 2);
	auto cn2 = std::make_shared<CNOT>(0, 1);
	auto h2 = std::make_shared<Hadamard>(0);
	auto m0 = std::make_shared<Measure>(0, 0);
	auto m1 = std::make_shared<Measure>(1,1);
	auto m2 = std::make_shared<Measure>(2,2);

	auto cond1 = std::make_shared<ConditionalFunction>(0);
	auto z = std::make_shared<Z>(2);
	cond1->addInstruction(z);
	auto cond2 = std::make_shared<ConditionalFunction>(1);
	auto x2 = std::make_shared<X>(2);
	cond2->addInstruction(x2);

	f->addInstruction(x);
	f->addInstruction(h);
	f->addInstruction(cn1);
	f->addInstruction(cn2);
	f->addInstruction(h2);
	f->addInstruction(m0);
	f->addInstruction(m1);
	f->addInstruction(cond1);
	f->addInstruction(cond2);
	f->addInstruction(m2);

	acc.execute(buffer, f);

}

BOOST_AUTO_TEST_CASE(checkKernelPhysicalExecution) {

	std::ifstream t(std::string(XACC_IBM_SOURCE_DIR) + "/tests/files/fakePostResponsePhysical.json");
	std::ifstream t2(std::string(XACC_IBM_SOURCE_DIR) + "/tests/files/fakeGetResultsPhysical.json");

	std::stringstream buffer, buffer2;
	buffer << t.rdbuf();
	buffer2 << t2.rdbuf();

	auto fakeClient = std::make_shared<FakeRestClient>(fakeLogin, fakeBackends,
			buffer.str(), buffer2.str());

	auto f = std::make_shared<GateFunction>("foo");

	IBMAccelerator acc(fakeClient);
	acc.initialize();
	auto qbits = acc.createBuffer("qubits", 2);

	acc.execute(qbits, f);
}

