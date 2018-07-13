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
#include <iostream>
#include <IRProvider.hpp>
#include <boost/math/constants/constants.hpp>
#include "exprtk.hpp"
#include "OQASMToXACCListener.hpp"
#include "XACC.hpp"

using namespace oqasm;
using symbol_table_t = exprtk::symbol_table<double>;
using expression_t = exprtk::expression<double>;
using parser_t = exprtk::parser<double>;

namespace xacc {

    namespace quantum {

        constexpr static double pi = boost::math::constants::pi<double>();

        OQASMToXACCListener::OQASMToXACCListener() {
            gateRegistry = xacc::getService<IRProvider>("gate");
            f = gateRegistry->createFunction("main", {}, {});
        }

        std::shared_ptr<Function> OQASMToXACCListener::getKernel() {
            return f;
        }

        double evalMathExpression(const std::string &expression) {
            symbol_table_t symbol_table;
            symbol_table.add_constant("pi", pi);
            expression_t expr;
            expr.register_symbol_table(symbol_table);
            parser_t parser;
            parser.compile(expression, expr);
            return expr.value();
        }

        double approxEquals(double a, double b, double tolerance=0.0001) {
            return round(a / tolerance) == round(b / tolerance);
        }

        void OQASMToXACCListener::exitU(oqasm::OQASM2Parser::UContext *ctx) {
            std::vector<int> qubits;
            std::vector<InstructionParameter> params;
            std::string gateName;

            qubits.push_back(std::stoi(ctx->gatearg()->INT()->getText()));
            auto theta = evalMathExpression(ctx->explist()->exp()->getText());
            auto phi = evalMathExpression(ctx->explist()->explist()->exp()->getText());
            auto lambda = evalMathExpression(ctx->explist()->explist()->explist()->exp()->getText());

            if (approxEquals(phi, -pi / 2.0) && approxEquals(lambda, pi / 2.0)) {
                gateName = "Rx";
                params.push_back(theta);
            } else if (phi == 0 && lambda == 0) {
                gateName = "Ry";
                params.push_back(theta);
            } else if (theta == 0 && phi == 0) {
                gateName = "Rz";
                params.push_back(lambda);
            } else {
                xacc::error("General single qubit gate 'U' not yet supported.");
            }

            std::shared_ptr<xacc::Instruction> instruction = gateRegistry->createInstruction(gateName, qubits);
            for (int i = 0; i < params.size(); i++) {
                instruction->setParameter(i, params[i]);
            }
            f->addInstruction(instruction);
        }

        void OQASMToXACCListener::exitCX(oqasm::OQASM2Parser::CXContext *ctx) {
            std::vector<int> qubits;
            qubits.push_back(std::stoi(ctx->gatearg(0)->INT()->getText()));
            qubits.push_back(std::stoi(ctx->gatearg(1)->INT()->getText()));

            std::shared_ptr<xacc::Instruction> instruction = gateRegistry->createInstruction("CNOT", qubits);
            f->addInstruction(instruction);
        }

        void OQASMToXACCListener::exitUserDefGate(oqasm::OQASM2Parser::UserDefGateContext *ctx) {
            std::string gateName = ctx->gatename()->id()->getText();
            gateName[0] = static_cast<char>(toupper(gateName[0]));
            std::vector<int> qubits;
            // TODO: check for params
            qubits.push_back(std::stoi(ctx->gatearglist()->gatearg()->INT()->getText()));

            std::shared_ptr<xacc::Instruction> instruction = gateRegistry->createInstruction(gateName, qubits);
            f->addInstruction(instruction);
        }
    }
}
