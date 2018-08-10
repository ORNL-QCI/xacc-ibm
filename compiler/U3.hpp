/***********************************************************************************
 * Copyright (c) 2018, UT-Battelle
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
 *   Initial implementation - H. Charles Zhao
 *
 **********************************************************************************/
#ifndef QUANTUM_GATE_GATEQIR_INSTRUCTIONS_U3_HPP_
#define QUANTUM_GATE_GATEQIR_INSTRUCTIONS_U3_HPP_

#include "GateInstruction.hpp"

namespace xacc {
    namespace quantum {
        class U3 : public virtual GateInstruction {
        public:
            U3() : GateInstruction("U3", std::vector<InstructionParameter>{InstructionParameter(0.0),
                                                                           InstructionParameter(0.0),
                                                                           InstructionParameter(0.0)}) {
            }

            U3(int qbit, double theta, double phi, double lambda) : GateInstruction("U3", std::vector<int>{qbit},
                                                                                    std::vector<InstructionParameter>{
                                                                                            InstructionParameter(theta),
                                                                                            InstructionParameter(phi),
                                                                                            InstructionParameter(
                                                                                                    lambda)}) {
            }

            U3(std::vector<int> qbits) : GateInstruction("U3", qbits,
                                                         std::vector<InstructionParameter>{InstructionParameter(0.0),
                                                                                           InstructionParameter(0.0),
                                                                                           InstructionParameter(0.0)}) {
            }

            virtual std::shared_ptr<GateInstruction> clone() {
                return std::make_shared<U3>();
            }

            /**
             * Return the description of this instance
             *
             * @return description The description of this object.
             */
            virtual const std::string description() const {
                return "";
            }

            DEFINE_VISITABLE()
        };
    }
}

#endif
