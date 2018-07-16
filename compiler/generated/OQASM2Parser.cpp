
// Generated from OQASM2.g4 by ANTLR 4.7.1


#include "OQASM2Listener.h"

#include "OQASM2Parser.h"


using namespace antlrcpp;
using namespace oqasm;
using namespace antlr4;

OQASM2Parser::OQASM2Parser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

OQASM2Parser::~OQASM2Parser() {
  delete _interpreter;
}

std::string OQASM2Parser::getGrammarFileName() const {
  return "OQASM2.g4";
}

const std::vector<std::string>& OQASM2Parser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& OQASM2Parser::getVocabulary() const {
  return _vocabulary;
}


//----------------- MainprogContext ------------------------------------------------------------------

OQASM2Parser::MainprogContext::MainprogContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OQASM2Parser::MainprogContext::OPENQASM() {
  return getToken(OQASM2Parser::OPENQASM, 0);
}

OQASM2Parser::RealContext* OQASM2Parser::MainprogContext::real() {
  return getRuleContext<OQASM2Parser::RealContext>(0);
}

tree::TerminalNode* OQASM2Parser::MainprogContext::EOL() {
  return getToken(OQASM2Parser::EOL, 0);
}

std::vector<OQASM2Parser::CommentContext *> OQASM2Parser::MainprogContext::comment() {
  return getRuleContexts<OQASM2Parser::CommentContext>();
}

OQASM2Parser::CommentContext* OQASM2Parser::MainprogContext::comment(size_t i) {
  return getRuleContext<OQASM2Parser::CommentContext>(i);
}

OQASM2Parser::ProgramContext* OQASM2Parser::MainprogContext::program() {
  return getRuleContext<OQASM2Parser::ProgramContext>(0);
}


size_t OQASM2Parser::MainprogContext::getRuleIndex() const {
  return OQASM2Parser::RuleMainprog;
}

void OQASM2Parser::MainprogContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMainprog(this);
}

void OQASM2Parser::MainprogContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMainprog(this);
}

OQASM2Parser::MainprogContext* OQASM2Parser::mainprog() {
  MainprogContext *_localctx = _tracker.createInstance<MainprogContext>(_ctx, getState());
  enterRule(_localctx, 0, OQASM2Parser::RuleMainprog);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == OQASM2Parser::COMMENT) {
      setState(80);
      comment();
      setState(85);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(86);
    match(OQASM2Parser::OPENQASM);
    setState(87);
    real();
    setState(88);
    match(OQASM2Parser::T__0);
    setState(89);
    match(OQASM2Parser::EOL);
    setState(91);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << OQASM2Parser::T__1)
      | (1ULL << OQASM2Parser::T__9)
      | (1ULL << OQASM2Parser::T__10)
      | (1ULL << OQASM2Parser::T__11)
      | (1ULL << OQASM2Parser::COMMENT)
      | (1ULL << OQASM2Parser::QREG)
      | (1ULL << OQASM2Parser::CREG)
      | (1ULL << OQASM2Parser::GATE)
      | (1ULL << OQASM2Parser::MEASURE)
      | (1ULL << OQASM2Parser::RESET)
      | (1ULL << OQASM2Parser::BARRIER)
      | (1ULL << OQASM2Parser::OPAQUE)
      | (1ULL << OQASM2Parser::ID))) != 0)) {
      setState(90);
      program();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

OQASM2Parser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<OQASM2Parser::LineContext *> OQASM2Parser::ProgramContext::line() {
  return getRuleContexts<OQASM2Parser::LineContext>();
}

OQASM2Parser::LineContext* OQASM2Parser::ProgramContext::line(size_t i) {
  return getRuleContext<OQASM2Parser::LineContext>(i);
}


size_t OQASM2Parser::ProgramContext::getRuleIndex() const {
  return OQASM2Parser::RuleProgram;
}

void OQASM2Parser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void OQASM2Parser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

OQASM2Parser::ProgramContext* OQASM2Parser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 2, OQASM2Parser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(93);
      line();
      setState(96); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << OQASM2Parser::T__1)
      | (1ULL << OQASM2Parser::T__9)
      | (1ULL << OQASM2Parser::T__10)
      | (1ULL << OQASM2Parser::T__11)
      | (1ULL << OQASM2Parser::COMMENT)
      | (1ULL << OQASM2Parser::QREG)
      | (1ULL << OQASM2Parser::CREG)
      | (1ULL << OQASM2Parser::GATE)
      | (1ULL << OQASM2Parser::MEASURE)
      | (1ULL << OQASM2Parser::RESET)
      | (1ULL << OQASM2Parser::BARRIER)
      | (1ULL << OQASM2Parser::OPAQUE)
      | (1ULL << OQASM2Parser::ID))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineContext ------------------------------------------------------------------

OQASM2Parser::LineContext::LineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OQASM2Parser::LineContext::EOL() {
  return getToken(OQASM2Parser::EOL, 0);
}

std::vector<OQASM2Parser::StatementContext *> OQASM2Parser::LineContext::statement() {
  return getRuleContexts<OQASM2Parser::StatementContext>();
}

OQASM2Parser::StatementContext* OQASM2Parser::LineContext::statement(size_t i) {
  return getRuleContext<OQASM2Parser::StatementContext>(i);
}

OQASM2Parser::CommentContext* OQASM2Parser::LineContext::comment() {
  return getRuleContext<OQASM2Parser::CommentContext>(0);
}

std::vector<OQASM2Parser::IncludeContext *> OQASM2Parser::LineContext::include() {
  return getRuleContexts<OQASM2Parser::IncludeContext>();
}

OQASM2Parser::IncludeContext* OQASM2Parser::LineContext::include(size_t i) {
  return getRuleContext<OQASM2Parser::IncludeContext>(i);
}


size_t OQASM2Parser::LineContext::getRuleIndex() const {
  return OQASM2Parser::RuleLine;
}

void OQASM2Parser::LineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLine(this);
}

void OQASM2Parser::LineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLine(this);
}

OQASM2Parser::LineContext* OQASM2Parser::line() {
  LineContext *_localctx = _tracker.createInstance<LineContext>(_ctx, getState());
  enterRule(_localctx, 4, OQASM2Parser::RuleLine);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(113);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case OQASM2Parser::T__9:
      case OQASM2Parser::T__10:
      case OQASM2Parser::T__11:
      case OQASM2Parser::QREG:
      case OQASM2Parser::CREG:
      case OQASM2Parser::GATE:
      case OQASM2Parser::MEASURE:
      case OQASM2Parser::RESET:
      case OQASM2Parser::BARRIER:
      case OQASM2Parser::OPAQUE:
      case OQASM2Parser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(99); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(98);
          statement();
          setState(101); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << OQASM2Parser::T__9)
          | (1ULL << OQASM2Parser::T__10)
          | (1ULL << OQASM2Parser::T__11)
          | (1ULL << OQASM2Parser::QREG)
          | (1ULL << OQASM2Parser::CREG)
          | (1ULL << OQASM2Parser::GATE)
          | (1ULL << OQASM2Parser::MEASURE)
          | (1ULL << OQASM2Parser::RESET)
          | (1ULL << OQASM2Parser::BARRIER)
          | (1ULL << OQASM2Parser::OPAQUE)
          | (1ULL << OQASM2Parser::ID))) != 0));
        setState(103);
        match(OQASM2Parser::EOL);
        break;
      }

      case OQASM2Parser::COMMENT: {
        enterOuterAlt(_localctx, 2);
        setState(105);
        comment();
        break;
      }

      case OQASM2Parser::T__1: {
        enterOuterAlt(_localctx, 3);
        setState(107); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(106);
          include();
          setState(109); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == OQASM2Parser::T__1);
        setState(111);
        match(OQASM2Parser::EOL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

OQASM2Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OQASM2Parser::RegdeclContext* OQASM2Parser::StatementContext::regdecl() {
  return getRuleContext<OQASM2Parser::RegdeclContext>(0);
}

OQASM2Parser::GatedeclContext* OQASM2Parser::StatementContext::gatedecl() {
  return getRuleContext<OQASM2Parser::GatedeclContext>(0);
}

OQASM2Parser::OpaqueContext* OQASM2Parser::StatementContext::opaque() {
  return getRuleContext<OQASM2Parser::OpaqueContext>(0);
}

OQASM2Parser::QopContext* OQASM2Parser::StatementContext::qop() {
  return getRuleContext<OQASM2Parser::QopContext>(0);
}

OQASM2Parser::ConditionalContext* OQASM2Parser::StatementContext::conditional() {
  return getRuleContext<OQASM2Parser::ConditionalContext>(0);
}


size_t OQASM2Parser::StatementContext::getRuleIndex() const {
  return OQASM2Parser::RuleStatement;
}

void OQASM2Parser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void OQASM2Parser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

OQASM2Parser::StatementContext* OQASM2Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 6, OQASM2Parser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(128);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case OQASM2Parser::QREG:
      case OQASM2Parser::CREG: {
        enterOuterAlt(_localctx, 1);
        setState(115);
        regdecl();
        setState(116);
        match(OQASM2Parser::T__0);
        break;
      }

      case OQASM2Parser::GATE: {
        enterOuterAlt(_localctx, 2);
        setState(118);
        gatedecl();
        break;
      }

      case OQASM2Parser::OPAQUE: {
        enterOuterAlt(_localctx, 3);
        setState(119);
        opaque();
        setState(120);
        match(OQASM2Parser::T__0);
        break;
      }

      case OQASM2Parser::T__9:
      case OQASM2Parser::T__10:
      case OQASM2Parser::MEASURE:
      case OQASM2Parser::RESET:
      case OQASM2Parser::BARRIER:
      case OQASM2Parser::ID: {
        enterOuterAlt(_localctx, 4);
        setState(122);
        qop();
        setState(123);
        match(OQASM2Parser::T__0);
        break;
      }

      case OQASM2Parser::T__11: {
        enterOuterAlt(_localctx, 5);
        setState(125);
        conditional();
        setState(126);
        match(OQASM2Parser::T__0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommentContext ------------------------------------------------------------------

OQASM2Parser::CommentContext::CommentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OQASM2Parser::CommentContext::COMMENT() {
  return getToken(OQASM2Parser::COMMENT, 0);
}


size_t OQASM2Parser::CommentContext::getRuleIndex() const {
  return OQASM2Parser::RuleComment;
}

void OQASM2Parser::CommentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComment(this);
}

void OQASM2Parser::CommentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComment(this);
}

OQASM2Parser::CommentContext* OQASM2Parser::comment() {
  CommentContext *_localctx = _tracker.createInstance<CommentContext>(_ctx, getState());
  enterRule(_localctx, 8, OQASM2Parser::RuleComment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    match(OQASM2Parser::COMMENT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IncludeContext ------------------------------------------------------------------

OQASM2Parser::IncludeContext::IncludeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OQASM2Parser::FilenameContext* OQASM2Parser::IncludeContext::filename() {
  return getRuleContext<OQASM2Parser::FilenameContext>(0);
}


size_t OQASM2Parser::IncludeContext::getRuleIndex() const {
  return OQASM2Parser::RuleInclude;
}

void OQASM2Parser::IncludeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInclude(this);
}

void OQASM2Parser::IncludeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInclude(this);
}

OQASM2Parser::IncludeContext* OQASM2Parser::include() {
  IncludeContext *_localctx = _tracker.createInstance<IncludeContext>(_ctx, getState());
  enterRule(_localctx, 10, OQASM2Parser::RuleInclude);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(132);
    match(OQASM2Parser::T__1);
    setState(133);
    filename();
    setState(134);
    match(OQASM2Parser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FilenameContext ------------------------------------------------------------------

OQASM2Parser::FilenameContext::FilenameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OQASM2Parser::StringContext* OQASM2Parser::FilenameContext::string() {
  return getRuleContext<OQASM2Parser::StringContext>(0);
}


size_t OQASM2Parser::FilenameContext::getRuleIndex() const {
  return OQASM2Parser::RuleFilename;
}

void OQASM2Parser::FilenameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFilename(this);
}

void OQASM2Parser::FilenameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFilename(this);
}

OQASM2Parser::FilenameContext* OQASM2Parser::filename() {
  FilenameContext *_localctx = _tracker.createInstance<FilenameContext>(_ctx, getState());
  enterRule(_localctx, 12, OQASM2Parser::RuleFilename);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
    string();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RegdeclContext ------------------------------------------------------------------

OQASM2Parser::RegdeclContext::RegdeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OQASM2Parser::QregContext* OQASM2Parser::RegdeclContext::qreg() {
  return getRuleContext<OQASM2Parser::QregContext>(0);
}

OQASM2Parser::QregisterContext* OQASM2Parser::RegdeclContext::qregister() {
  return getRuleContext<OQASM2Parser::QregisterContext>(0);
}

OQASM2Parser::CregContext* OQASM2Parser::RegdeclContext::creg() {
  return getRuleContext<OQASM2Parser::CregContext>(0);
}

OQASM2Parser::CregisterContext* OQASM2Parser::RegdeclContext::cregister() {
  return getRuleContext<OQASM2Parser::CregisterContext>(0);
}


size_t OQASM2Parser::RegdeclContext::getRuleIndex() const {
  return OQASM2Parser::RuleRegdecl;
}

void OQASM2Parser::RegdeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRegdecl(this);
}

void OQASM2Parser::RegdeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRegdecl(this);
}

OQASM2Parser::RegdeclContext* OQASM2Parser::regdecl() {
  RegdeclContext *_localctx = _tracker.createInstance<RegdeclContext>(_ctx, getState());
  enterRule(_localctx, 14, OQASM2Parser::RuleRegdecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(144);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case OQASM2Parser::QREG: {
        enterOuterAlt(_localctx, 1);
        setState(138);
        qreg();
        setState(139);
        qregister();
        break;
      }

      case OQASM2Parser::CREG: {
        enterOuterAlt(_localctx, 2);
        setState(141);
        creg();
        setState(142);
        cregister();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QregisterContext ------------------------------------------------------------------

OQASM2Parser::QregisterContext::QregisterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OQASM2Parser::IdContext* OQASM2Parser::QregisterContext::id() {
  return getRuleContext<OQASM2Parser::IdContext>(0);
}

OQASM2Parser::RegistersizeContext* OQASM2Parser::QregisterContext::registersize() {
  return getRuleContext<OQASM2Parser::RegistersizeContext>(0);
}


size_t OQASM2Parser::QregisterContext::getRuleIndex() const {
  return OQASM2Parser::RuleQregister;
}

void OQASM2Parser::QregisterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQregister(this);
}

void OQASM2Parser::QregisterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQregister(this);
}

OQASM2Parser::QregisterContext* OQASM2Parser::qregister() {
  QregisterContext *_localctx = _tracker.createInstance<QregisterContext>(_ctx, getState());
  enterRule(_localctx, 16, OQASM2Parser::RuleQregister);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(152);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(146);
      id();
      setState(147);
      match(OQASM2Parser::T__2);
      setState(148);
      registersize();
      setState(149);
      match(OQASM2Parser::T__3);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(151);
      id();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CregisterContext ------------------------------------------------------------------

OQASM2Parser::CregisterContext::CregisterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OQASM2Parser::IdContext* OQASM2Parser::CregisterContext::id() {
  return getRuleContext<OQASM2Parser::IdContext>(0);
}

OQASM2Parser::RegistersizeContext* OQASM2Parser::CregisterContext::registersize() {
  return getRuleContext<OQASM2Parser::RegistersizeContext>(0);
}


size_t OQASM2Parser::CregisterContext::getRuleIndex() const {
  return OQASM2Parser::RuleCregister;
}

void OQASM2Parser::CregisterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCregister(this);
}

void OQASM2Parser::CregisterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCregister(this);
}

OQASM2Parser::CregisterContext* OQASM2Parser::cregister() {
  CregisterContext *_localctx = _tracker.createInstance<CregisterContext>(_ctx, getState());
  enterRule(_localctx, 18, OQASM2Parser::RuleCregister);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(160);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(154);
      id();
      setState(155);
      match(OQASM2Parser::T__2);
      setState(156);
      registersize();
      setState(157);
      match(OQASM2Parser::T__3);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(159);
      id();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RegistersizeContext ------------------------------------------------------------------

OQASM2Parser::RegistersizeContext::RegistersizeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OQASM2Parser::RegistersizeContext::INT() {
  return getToken(OQASM2Parser::INT, 0);
}


size_t OQASM2Parser::RegistersizeContext::getRuleIndex() const {
  return OQASM2Parser::RuleRegistersize;
}

void OQASM2Parser::RegistersizeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRegistersize(this);
}

void OQASM2Parser::RegistersizeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRegistersize(this);
}

OQASM2Parser::RegistersizeContext* OQASM2Parser::registersize() {
  RegistersizeContext *_localctx = _tracker.createInstance<RegistersizeContext>(_ctx, getState());
  enterRule(_localctx, 20, OQASM2Parser::RuleRegistersize);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    match(OQASM2Parser::INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GatedeclContext ------------------------------------------------------------------

OQASM2Parser::GatedeclContext::GatedeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OQASM2Parser::GateContext* OQASM2Parser::GatedeclContext::gate() {
  return getRuleContext<OQASM2Parser::GateContext>(0);
}

OQASM2Parser::GatenameContext* OQASM2Parser::GatedeclContext::gatename() {
  return getRuleContext<OQASM2Parser::GatenameContext>(0);
}

OQASM2Parser::GatearglistContext* OQASM2Parser::GatedeclContext::gatearglist() {
  return getRuleContext<OQASM2Parser::GatearglistContext>(0);
}

OQASM2Parser::GatebodyContext* OQASM2Parser::GatedeclContext::gatebody() {
  return getRuleContext<OQASM2Parser::GatebodyContext>(0);
}


size_t OQASM2Parser::GatedeclContext::getRuleIndex() const {
  return OQASM2Parser::RuleGatedecl;
}

void OQASM2Parser::GatedeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGatedecl(this);
}

void OQASM2Parser::GatedeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGatedecl(this);
}

OQASM2Parser::GatedeclContext* OQASM2Parser::gatedecl() {
  GatedeclContext *_localctx = _tracker.createInstance<GatedeclContext>(_ctx, getState());
  enterRule(_localctx, 22, OQASM2Parser::RuleGatedecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(164);
    gate();
    setState(165);
    gatename();
    setState(166);
    gatearglist();
    setState(168);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == OQASM2Parser::T__7) {
      setState(167);
      gatebody();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GatenameContext ------------------------------------------------------------------

OQASM2Parser::GatenameContext::GatenameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OQASM2Parser::IdContext* OQASM2Parser::GatenameContext::id() {
  return getRuleContext<OQASM2Parser::IdContext>(0);
}

OQASM2Parser::ParamlistContext* OQASM2Parser::GatenameContext::paramlist() {
  return getRuleContext<OQASM2Parser::ParamlistContext>(0);
}


size_t OQASM2Parser::GatenameContext::getRuleIndex() const {
  return OQASM2Parser::RuleGatename;
}

void OQASM2Parser::GatenameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGatename(this);
}

void OQASM2Parser::GatenameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGatename(this);
}

OQASM2Parser::GatenameContext* OQASM2Parser::gatename() {
  GatenameContext *_localctx = _tracker.createInstance<GatenameContext>(_ctx, getState());
  enterRule(_localctx, 24, OQASM2Parser::RuleGatename);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(178);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(170);
      id();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(171);
      id();
      setState(172);
      match(OQASM2Parser::T__4);
      setState(174);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == OQASM2Parser::ID) {
        setState(173);
        paramlist();
      }
      setState(176);
      match(OQASM2Parser::T__5);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GatearglistContext ------------------------------------------------------------------

OQASM2Parser::GatearglistContext::GatearglistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OQASM2Parser::GateargContext* OQASM2Parser::GatearglistContext::gatearg() {
  return getRuleContext<OQASM2Parser::GateargContext>(0);
}

OQASM2Parser::GatearglistContext* OQASM2Parser::GatearglistContext::gatearglist() {
  return getRuleContext<OQASM2Parser::GatearglistContext>(0);
}


size_t OQASM2Parser::GatearglistContext::getRuleIndex() const {
  return OQASM2Parser::RuleGatearglist;
}

void OQASM2Parser::GatearglistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGatearglist(this);
}

void OQASM2Parser::GatearglistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGatearglist(this);
}

OQASM2Parser::GatearglistContext* OQASM2Parser::gatearglist() {
  GatearglistContext *_localctx = _tracker.createInstance<GatearglistContext>(_ctx, getState());
  enterRule(_localctx, 26, OQASM2Parser::RuleGatearglist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(180);
    gatearg();
    setState(183);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == OQASM2Parser::T__6) {
      setState(181);
      match(OQASM2Parser::T__6);
      setState(182);
      gatearglist();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GateargContext ------------------------------------------------------------------

OQASM2Parser::GateargContext::GateargContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OQASM2Parser::IdContext* OQASM2Parser::GateargContext::id() {
  return getRuleContext<OQASM2Parser::IdContext>(0);
}

tree::TerminalNode* OQASM2Parser::GateargContext::INT() {
  return getToken(OQASM2Parser::INT, 0);
}


size_t OQASM2Parser::GateargContext::getRuleIndex() const {
  return OQASM2Parser::RuleGatearg;
}

void OQASM2Parser::GateargContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGatearg(this);
}

void OQASM2Parser::GateargContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGatearg(this);
}

OQASM2Parser::GateargContext* OQASM2Parser::gatearg() {
  GateargContext *_localctx = _tracker.createInstance<GateargContext>(_ctx, getState());
  enterRule(_localctx, 28, OQASM2Parser::RuleGatearg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(191);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(185);
      id();
      setState(186);
      match(OQASM2Parser::T__2);
      setState(187);
      match(OQASM2Parser::INT);
      setState(188);
      match(OQASM2Parser::T__3);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(190);
      id();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GatebodyContext ------------------------------------------------------------------

OQASM2Parser::GatebodyContext::GatebodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OQASM2Parser::GateprogContext* OQASM2Parser::GatebodyContext::gateprog() {
  return getRuleContext<OQASM2Parser::GateprogContext>(0);
}


size_t OQASM2Parser::GatebodyContext::getRuleIndex() const {
  return OQASM2Parser::RuleGatebody;
}

void OQASM2Parser::GatebodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGatebody(this);
}

void OQASM2Parser::GatebodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGatebody(this);
}

OQASM2Parser::GatebodyContext* OQASM2Parser::gatebody() {
  GatebodyContext *_localctx = _tracker.createInstance<GatebodyContext>(_ctx, getState());
  enterRule(_localctx, 30, OQASM2Parser::RuleGatebody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(193);
    match(OQASM2Parser::T__7);
    setState(194);
    gateprog();
    setState(195);
    match(OQASM2Parser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GateprogContext ------------------------------------------------------------------

OQASM2Parser::GateprogContext::GateprogContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<OQASM2Parser::GatelineContext *> OQASM2Parser::GateprogContext::gateline() {
  return getRuleContexts<OQASM2Parser::GatelineContext>();
}

OQASM2Parser::GatelineContext* OQASM2Parser::GateprogContext::gateline(size_t i) {
  return getRuleContext<OQASM2Parser::GatelineContext>(i);
}


size_t OQASM2Parser::GateprogContext::getRuleIndex() const {
  return OQASM2Parser::RuleGateprog;
}

void OQASM2Parser::GateprogContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGateprog(this);
}

void OQASM2Parser::GateprogContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGateprog(this);
}

OQASM2Parser::GateprogContext* OQASM2Parser::gateprog() {
  GateprogContext *_localctx = _tracker.createInstance<GateprogContext>(_ctx, getState());
  enterRule(_localctx, 32, OQASM2Parser::RuleGateprog);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(200);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << OQASM2Parser::T__9)
      | (1ULL << OQASM2Parser::T__10)
      | (1ULL << OQASM2Parser::ID))) != 0)) {
      setState(197);
      gateline();
      setState(202);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GatelineContext ------------------------------------------------------------------

OQASM2Parser::GatelineContext::GatelineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OQASM2Parser::UopContext* OQASM2Parser::GatelineContext::uop() {
  return getRuleContext<OQASM2Parser::UopContext>(0);
}


size_t OQASM2Parser::GatelineContext::getRuleIndex() const {
  return OQASM2Parser::RuleGateline;
}

void OQASM2Parser::GatelineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGateline(this);
}

void OQASM2Parser::GatelineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGateline(this);
}

OQASM2Parser::GatelineContext* OQASM2Parser::gateline() {
  GatelineContext *_localctx = _tracker.createInstance<GatelineContext>(_ctx, getState());
  enterRule(_localctx, 34, OQASM2Parser::RuleGateline);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(203);
    uop();
    setState(204);
    match(OQASM2Parser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamlistContext ------------------------------------------------------------------

OQASM2Parser::ParamlistContext::ParamlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OQASM2Parser::ParamContext* OQASM2Parser::ParamlistContext::param() {
  return getRuleContext<OQASM2Parser::ParamContext>(0);
}

OQASM2Parser::ParamlistContext* OQASM2Parser::ParamlistContext::paramlist() {
  return getRuleContext<OQASM2Parser::ParamlistContext>(0);
}


size_t OQASM2Parser::ParamlistContext::getRuleIndex() const {
  return OQASM2Parser::RuleParamlist;
}

void OQASM2Parser::ParamlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamlist(this);
}

void OQASM2Parser::ParamlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamlist(this);
}

OQASM2Parser::ParamlistContext* OQASM2Parser::paramlist() {
  ParamlistContext *_localctx = _tracker.createInstance<ParamlistContext>(_ctx, getState());
  enterRule(_localctx, 36, OQASM2Parser::RuleParamlist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
    param();
    setState(209);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == OQASM2Parser::T__6) {
      setState(207);
      match(OQASM2Parser::T__6);
      setState(208);
      paramlist();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

OQASM2Parser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OQASM2Parser::IdContext* OQASM2Parser::ParamContext::id() {
  return getRuleContext<OQASM2Parser::IdContext>(0);
}


size_t OQASM2Parser::ParamContext::getRuleIndex() const {
  return OQASM2Parser::RuleParam;
}

void OQASM2Parser::ParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam(this);
}

void OQASM2Parser::ParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam(this);
}

OQASM2Parser::ParamContext* OQASM2Parser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 38, OQASM2Parser::RuleParam);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(211);
    id();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpaqueContext ------------------------------------------------------------------

OQASM2Parser::OpaqueContext::OpaqueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OQASM2Parser::OpaqueContext::OPAQUE() {
  return getToken(OQASM2Parser::OPAQUE, 0);
}

OQASM2Parser::OpaquenameContext* OQASM2Parser::OpaqueContext::opaquename() {
  return getRuleContext<OQASM2Parser::OpaquenameContext>(0);
}

OQASM2Parser::OpaquearglistContext* OQASM2Parser::OpaqueContext::opaquearglist() {
  return getRuleContext<OQASM2Parser::OpaquearglistContext>(0);
}


size_t OQASM2Parser::OpaqueContext::getRuleIndex() const {
  return OQASM2Parser::RuleOpaque;
}

void OQASM2Parser::OpaqueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpaque(this);
}

void OQASM2Parser::OpaqueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpaque(this);
}

OQASM2Parser::OpaqueContext* OQASM2Parser::opaque() {
  OpaqueContext *_localctx = _tracker.createInstance<OpaqueContext>(_ctx, getState());
  enterRule(_localctx, 40, OQASM2Parser::RuleOpaque);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
    match(OQASM2Parser::OPAQUE);
    setState(214);
    opaquename();
    setState(215);
    opaquearglist();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpaquenameContext ------------------------------------------------------------------

OQASM2Parser::OpaquenameContext::OpaquenameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OQASM2Parser::IdContext* OQASM2Parser::OpaquenameContext::id() {
  return getRuleContext<OQASM2Parser::IdContext>(0);
}

OQASM2Parser::ParamlistContext* OQASM2Parser::OpaquenameContext::paramlist() {
  return getRuleContext<OQASM2Parser::ParamlistContext>(0);
}


size_t OQASM2Parser::OpaquenameContext::getRuleIndex() const {
  return OQASM2Parser::RuleOpaquename;
}

void OQASM2Parser::OpaquenameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpaquename(this);
}

void OQASM2Parser::OpaquenameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpaquename(this);
}

OQASM2Parser::OpaquenameContext* OQASM2Parser::opaquename() {
  OpaquenameContext *_localctx = _tracker.createInstance<OpaquenameContext>(_ctx, getState());
  enterRule(_localctx, 42, OQASM2Parser::RuleOpaquename);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(225);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(217);
      id();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(218);
      id();
      setState(219);
      match(OQASM2Parser::T__4);
      setState(221);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == OQASM2Parser::ID) {
        setState(220);
        paramlist();
      }
      setState(223);
      match(OQASM2Parser::T__5);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpaquearglistContext ------------------------------------------------------------------

OQASM2Parser::OpaquearglistContext::OpaquearglistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OQASM2Parser::OpaqueargContext* OQASM2Parser::OpaquearglistContext::opaquearg() {
  return getRuleContext<OQASM2Parser::OpaqueargContext>(0);
}

OQASM2Parser::OpaquearglistContext* OQASM2Parser::OpaquearglistContext::opaquearglist() {
  return getRuleContext<OQASM2Parser::OpaquearglistContext>(0);
}


size_t OQASM2Parser::OpaquearglistContext::getRuleIndex() const {
  return OQASM2Parser::RuleOpaquearglist;
}

void OQASM2Parser::OpaquearglistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpaquearglist(this);
}

void OQASM2Parser::OpaquearglistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpaquearglist(this);
}

OQASM2Parser::OpaquearglistContext* OQASM2Parser::opaquearglist() {
  OpaquearglistContext *_localctx = _tracker.createInstance<OpaquearglistContext>(_ctx, getState());
  enterRule(_localctx, 44, OQASM2Parser::RuleOpaquearglist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(227);
    opaquearg();
    setState(230);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == OQASM2Parser::T__6) {
      setState(228);
      match(OQASM2Parser::T__6);
      setState(229);
      opaquearglist();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpaqueargContext ------------------------------------------------------------------

OQASM2Parser::OpaqueargContext::OpaqueargContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OQASM2Parser::IdContext* OQASM2Parser::OpaqueargContext::id() {
  return getRuleContext<OQASM2Parser::IdContext>(0);
}

tree::TerminalNode* OQASM2Parser::OpaqueargContext::INT() {
  return getToken(OQASM2Parser::INT, 0);
}


size_t OQASM2Parser::OpaqueargContext::getRuleIndex() const {
  return OQASM2Parser::RuleOpaquearg;
}

void OQASM2Parser::OpaqueargContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpaquearg(this);
}

void OQASM2Parser::OpaqueargContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpaquearg(this);
}

OQASM2Parser::OpaqueargContext* OQASM2Parser::opaquearg() {
  OpaqueargContext *_localctx = _tracker.createInstance<OpaqueargContext>(_ctx, getState());
  enterRule(_localctx, 46, OQASM2Parser::RuleOpaquearg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    id();
    setState(233);
    match(OQASM2Parser::T__2);
    setState(234);
    match(OQASM2Parser::INT);
    setState(235);
    match(OQASM2Parser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QopContext ------------------------------------------------------------------

OQASM2Parser::QopContext::QopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OQASM2Parser::UopContext* OQASM2Parser::QopContext::uop() {
  return getRuleContext<OQASM2Parser::UopContext>(0);
}

OQASM2Parser::ReesetContext* OQASM2Parser::QopContext::reeset() {
  return getRuleContext<OQASM2Parser::ReesetContext>(0);
}

OQASM2Parser::MeasureContext* OQASM2Parser::QopContext::measure() {
  return getRuleContext<OQASM2Parser::MeasureContext>(0);
}

OQASM2Parser::BarrierContext* OQASM2Parser::QopContext::barrier() {
  return getRuleContext<OQASM2Parser::BarrierContext>(0);
}


size_t OQASM2Parser::QopContext::getRuleIndex() const {
  return OQASM2Parser::RuleQop;
}

void OQASM2Parser::QopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQop(this);
}

void OQASM2Parser::QopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQop(this);
}

OQASM2Parser::QopContext* OQASM2Parser::qop() {
  QopContext *_localctx = _tracker.createInstance<QopContext>(_ctx, getState());
  enterRule(_localctx, 48, OQASM2Parser::RuleQop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(241);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case OQASM2Parser::T__9:
      case OQASM2Parser::T__10:
      case OQASM2Parser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(237);
        uop();
        break;
      }

      case OQASM2Parser::RESET: {
        enterOuterAlt(_localctx, 2);
        setState(238);
        reeset();
        break;
      }

      case OQASM2Parser::MEASURE: {
        enterOuterAlt(_localctx, 3);
        setState(239);
        measure();
        break;
      }

      case OQASM2Parser::BARRIER: {
        enterOuterAlt(_localctx, 4);
        setState(240);
        barrier();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UopContext ------------------------------------------------------------------

OQASM2Parser::UopContext::UopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t OQASM2Parser::UopContext::getRuleIndex() const {
  return OQASM2Parser::RuleUop;
}

void OQASM2Parser::UopContext::copyFrom(UopContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UContext ------------------------------------------------------------------

OQASM2Parser::GateargContext* OQASM2Parser::UContext::gatearg() {
  return getRuleContext<OQASM2Parser::GateargContext>(0);
}

OQASM2Parser::ExplistContext* OQASM2Parser::UContext::explist() {
  return getRuleContext<OQASM2Parser::ExplistContext>(0);
}

OQASM2Parser::UContext::UContext(UopContext *ctx) { copyFrom(ctx); }

void OQASM2Parser::UContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterU(this);
}
void OQASM2Parser::UContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitU(this);
}
//----------------- CXContext ------------------------------------------------------------------

std::vector<OQASM2Parser::GateargContext *> OQASM2Parser::CXContext::gatearg() {
  return getRuleContexts<OQASM2Parser::GateargContext>();
}

OQASM2Parser::GateargContext* OQASM2Parser::CXContext::gatearg(size_t i) {
  return getRuleContext<OQASM2Parser::GateargContext>(i);
}

OQASM2Parser::CXContext::CXContext(UopContext *ctx) { copyFrom(ctx); }

void OQASM2Parser::CXContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCX(this);
}
void OQASM2Parser::CXContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCX(this);
}
//----------------- UserDefGateContext ------------------------------------------------------------------

OQASM2Parser::GatenameContext* OQASM2Parser::UserDefGateContext::gatename() {
  return getRuleContext<OQASM2Parser::GatenameContext>(0);
}

OQASM2Parser::GatearglistContext* OQASM2Parser::UserDefGateContext::gatearglist() {
  return getRuleContext<OQASM2Parser::GatearglistContext>(0);
}

OQASM2Parser::ExplistContext* OQASM2Parser::UserDefGateContext::explist() {
  return getRuleContext<OQASM2Parser::ExplistContext>(0);
}

OQASM2Parser::UserDefGateContext::UserDefGateContext(UopContext *ctx) { copyFrom(ctx); }

void OQASM2Parser::UserDefGateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUserDefGate(this);
}
void OQASM2Parser::UserDefGateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUserDefGate(this);
}
OQASM2Parser::UopContext* OQASM2Parser::uop() {
  UopContext *_localctx = _tracker.createInstance<UopContext>(_ctx, getState());
  enterRule(_localctx, 50, OQASM2Parser::RuleUop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(264);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case OQASM2Parser::T__9: {
        _localctx = dynamic_cast<UopContext *>(_tracker.createInstance<OQASM2Parser::UContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(243);
        match(OQASM2Parser::T__9);
        setState(244);
        match(OQASM2Parser::T__4);
        setState(246);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << OQASM2Parser::T__4)
          | (1ULL << OQASM2Parser::T__13)
          | (1ULL << OQASM2Parser::T__15)
          | (1ULL << OQASM2Parser::T__19)
          | (1ULL << OQASM2Parser::T__20)
          | (1ULL << OQASM2Parser::T__21)
          | (1ULL << OQASM2Parser::T__22)
          | (1ULL << OQASM2Parser::T__23)
          | (1ULL << OQASM2Parser::T__24)
          | (1ULL << OQASM2Parser::ID)
          | (1ULL << OQASM2Parser::REAL)
          | (1ULL << OQASM2Parser::INT))) != 0)) {
          setState(245);
          explist();
        }
        setState(248);
        match(OQASM2Parser::T__5);
        setState(249);
        gatearg();
        break;
      }

      case OQASM2Parser::T__10: {
        _localctx = dynamic_cast<UopContext *>(_tracker.createInstance<OQASM2Parser::CXContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(250);
        match(OQASM2Parser::T__10);
        setState(251);
        gatearg();
        setState(252);
        match(OQASM2Parser::T__6);
        setState(253);
        gatearg();
        break;
      }

      case OQASM2Parser::ID: {
        _localctx = dynamic_cast<UopContext *>(_tracker.createInstance<OQASM2Parser::UserDefGateContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(255);
        gatename();
        setState(260);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == OQASM2Parser::T__4) {
          setState(256);
          match(OQASM2Parser::T__4);
          setState(257);
          explist();
          setState(258);
          match(OQASM2Parser::T__5);
        }
        setState(262);
        gatearglist();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionalContext ------------------------------------------------------------------

OQASM2Parser::ConditionalContext::ConditionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OQASM2Parser::IdContext* OQASM2Parser::ConditionalContext::id() {
  return getRuleContext<OQASM2Parser::IdContext>(0);
}

tree::TerminalNode* OQASM2Parser::ConditionalContext::INT() {
  return getToken(OQASM2Parser::INT, 0);
}

OQASM2Parser::ActionContext* OQASM2Parser::ConditionalContext::action() {
  return getRuleContext<OQASM2Parser::ActionContext>(0);
}


size_t OQASM2Parser::ConditionalContext::getRuleIndex() const {
  return OQASM2Parser::RuleConditional;
}

void OQASM2Parser::ConditionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditional(this);
}

void OQASM2Parser::ConditionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditional(this);
}

OQASM2Parser::ConditionalContext* OQASM2Parser::conditional() {
  ConditionalContext *_localctx = _tracker.createInstance<ConditionalContext>(_ctx, getState());
  enterRule(_localctx, 52, OQASM2Parser::RuleConditional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(266);
    match(OQASM2Parser::T__11);
    setState(267);
    match(OQASM2Parser::T__4);
    setState(268);
    id();
    setState(269);
    match(OQASM2Parser::T__12);
    setState(270);
    match(OQASM2Parser::INT);
    setState(271);
    match(OQASM2Parser::T__5);
    setState(272);
    action();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ActionContext ------------------------------------------------------------------

OQASM2Parser::ActionContext::ActionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OQASM2Parser::QopContext* OQASM2Parser::ActionContext::qop() {
  return getRuleContext<OQASM2Parser::QopContext>(0);
}


size_t OQASM2Parser::ActionContext::getRuleIndex() const {
  return OQASM2Parser::RuleAction;
}

void OQASM2Parser::ActionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAction(this);
}

void OQASM2Parser::ActionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAction(this);
}

OQASM2Parser::ActionContext* OQASM2Parser::action() {
  ActionContext *_localctx = _tracker.createInstance<ActionContext>(_ctx, getState());
  enterRule(_localctx, 54, OQASM2Parser::RuleAction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(274);
    qop();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExplistContext ------------------------------------------------------------------

OQASM2Parser::ExplistContext::ExplistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<OQASM2Parser::ExpContext *> OQASM2Parser::ExplistContext::exp() {
  return getRuleContexts<OQASM2Parser::ExpContext>();
}

OQASM2Parser::ExpContext* OQASM2Parser::ExplistContext::exp(size_t i) {
  return getRuleContext<OQASM2Parser::ExpContext>(i);
}


size_t OQASM2Parser::ExplistContext::getRuleIndex() const {
  return OQASM2Parser::RuleExplist;
}

void OQASM2Parser::ExplistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExplist(this);
}

void OQASM2Parser::ExplistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExplist(this);
}

OQASM2Parser::ExplistContext* OQASM2Parser::explist() {
  ExplistContext *_localctx = _tracker.createInstance<ExplistContext>(_ctx, getState());
  enterRule(_localctx, 56, OQASM2Parser::RuleExplist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(276);
    exp(0);
    setState(281);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == OQASM2Parser::T__6) {
      setState(277);
      match(OQASM2Parser::T__6);
      setState(278);
      exp(0);
      setState(283);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

OQASM2Parser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OQASM2Parser::RealContext* OQASM2Parser::ExpContext::real() {
  return getRuleContext<OQASM2Parser::RealContext>(0);
}

tree::TerminalNode* OQASM2Parser::ExpContext::INT() {
  return getToken(OQASM2Parser::INT, 0);
}

OQASM2Parser::IdContext* OQASM2Parser::ExpContext::id() {
  return getRuleContext<OQASM2Parser::IdContext>(0);
}

std::vector<OQASM2Parser::ExpContext *> OQASM2Parser::ExpContext::exp() {
  return getRuleContexts<OQASM2Parser::ExpContext>();
}

OQASM2Parser::ExpContext* OQASM2Parser::ExpContext::exp(size_t i) {
  return getRuleContext<OQASM2Parser::ExpContext>(i);
}

OQASM2Parser::UnaryopContext* OQASM2Parser::ExpContext::unaryop() {
  return getRuleContext<OQASM2Parser::UnaryopContext>(0);
}


size_t OQASM2Parser::ExpContext::getRuleIndex() const {
  return OQASM2Parser::RuleExp;
}

void OQASM2Parser::ExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExp(this);
}

void OQASM2Parser::ExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExp(this);
}


OQASM2Parser::ExpContext* OQASM2Parser::exp() {
   return exp(0);
}

OQASM2Parser::ExpContext* OQASM2Parser::exp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  OQASM2Parser::ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, parentState);
  OQASM2Parser::ExpContext *previousContext = _localctx;
  size_t startState = 58;
  enterRecursionRule(_localctx, 58, OQASM2Parser::RuleExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(300);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case OQASM2Parser::REAL: {
        setState(285);
        real();
        break;
      }

      case OQASM2Parser::INT: {
        setState(286);
        match(OQASM2Parser::INT);
        break;
      }

      case OQASM2Parser::T__13: {
        setState(287);
        match(OQASM2Parser::T__13);
        break;
      }

      case OQASM2Parser::ID: {
        setState(288);
        id();
        break;
      }

      case OQASM2Parser::T__15: {
        setState(289);
        match(OQASM2Parser::T__15);
        setState(290);
        exp(4);
        break;
      }

      case OQASM2Parser::T__4: {
        setState(291);
        match(OQASM2Parser::T__4);
        setState(292);
        exp(0);
        setState(293);
        match(OQASM2Parser::T__5);
        break;
      }

      case OQASM2Parser::T__19:
      case OQASM2Parser::T__20:
      case OQASM2Parser::T__21:
      case OQASM2Parser::T__22:
      case OQASM2Parser::T__23:
      case OQASM2Parser::T__24: {
        setState(295);
        unaryop();
        setState(296);
        match(OQASM2Parser::T__4);
        setState(297);
        exp(0);
        setState(298);
        match(OQASM2Parser::T__5);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(319);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(317);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(302);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(303);
          match(OQASM2Parser::T__14);
          setState(304);
          exp(9);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(305);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(306);
          match(OQASM2Parser::T__15);
          setState(307);
          exp(8);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(308);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(309);
          match(OQASM2Parser::T__16);
          setState(310);
          exp(7);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(311);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(312);
          match(OQASM2Parser::T__17);
          setState(313);
          exp(6);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(314);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(315);
          match(OQASM2Parser::T__18);
          setState(316);
          exp(4);
          break;
        }

        } 
      }
      setState(321);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnaryopContext ------------------------------------------------------------------

OQASM2Parser::UnaryopContext::UnaryopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t OQASM2Parser::UnaryopContext::getRuleIndex() const {
  return OQASM2Parser::RuleUnaryop;
}

void OQASM2Parser::UnaryopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryop(this);
}

void OQASM2Parser::UnaryopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryop(this);
}

OQASM2Parser::UnaryopContext* OQASM2Parser::unaryop() {
  UnaryopContext *_localctx = _tracker.createInstance<UnaryopContext>(_ctx, getState());
  enterRule(_localctx, 60, OQASM2Parser::RuleUnaryop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(322);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << OQASM2Parser::T__19)
      | (1ULL << OQASM2Parser::T__20)
      | (1ULL << OQASM2Parser::T__21)
      | (1ULL << OQASM2Parser::T__22)
      | (1ULL << OQASM2Parser::T__23)
      | (1ULL << OQASM2Parser::T__24))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QregContext ------------------------------------------------------------------

OQASM2Parser::QregContext::QregContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OQASM2Parser::QregContext::QREG() {
  return getToken(OQASM2Parser::QREG, 0);
}


size_t OQASM2Parser::QregContext::getRuleIndex() const {
  return OQASM2Parser::RuleQreg;
}

void OQASM2Parser::QregContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQreg(this);
}

void OQASM2Parser::QregContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQreg(this);
}

OQASM2Parser::QregContext* OQASM2Parser::qreg() {
  QregContext *_localctx = _tracker.createInstance<QregContext>(_ctx, getState());
  enterRule(_localctx, 62, OQASM2Parser::RuleQreg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(324);
    match(OQASM2Parser::QREG);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CregContext ------------------------------------------------------------------

OQASM2Parser::CregContext::CregContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OQASM2Parser::CregContext::CREG() {
  return getToken(OQASM2Parser::CREG, 0);
}


size_t OQASM2Parser::CregContext::getRuleIndex() const {
  return OQASM2Parser::RuleCreg;
}

void OQASM2Parser::CregContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreg(this);
}

void OQASM2Parser::CregContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreg(this);
}

OQASM2Parser::CregContext* OQASM2Parser::creg() {
  CregContext *_localctx = _tracker.createInstance<CregContext>(_ctx, getState());
  enterRule(_localctx, 64, OQASM2Parser::RuleCreg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(326);
    match(OQASM2Parser::CREG);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GateContext ------------------------------------------------------------------

OQASM2Parser::GateContext::GateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OQASM2Parser::GateContext::GATE() {
  return getToken(OQASM2Parser::GATE, 0);
}


size_t OQASM2Parser::GateContext::getRuleIndex() const {
  return OQASM2Parser::RuleGate;
}

void OQASM2Parser::GateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGate(this);
}

void OQASM2Parser::GateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGate(this);
}

OQASM2Parser::GateContext* OQASM2Parser::gate() {
  GateContext *_localctx = _tracker.createInstance<GateContext>(_ctx, getState());
  enterRule(_localctx, 66, OQASM2Parser::RuleGate);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(328);
    match(OQASM2Parser::GATE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MeasureContext ------------------------------------------------------------------

OQASM2Parser::MeasureContext::MeasureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OQASM2Parser::MeasureContext::MEASURE() {
  return getToken(OQASM2Parser::MEASURE, 0);
}

OQASM2Parser::QregisterContext* OQASM2Parser::MeasureContext::qregister() {
  return getRuleContext<OQASM2Parser::QregisterContext>(0);
}

OQASM2Parser::CregisterContext* OQASM2Parser::MeasureContext::cregister() {
  return getRuleContext<OQASM2Parser::CregisterContext>(0);
}

std::vector<OQASM2Parser::GateargContext *> OQASM2Parser::MeasureContext::gatearg() {
  return getRuleContexts<OQASM2Parser::GateargContext>();
}

OQASM2Parser::GateargContext* OQASM2Parser::MeasureContext::gatearg(size_t i) {
  return getRuleContext<OQASM2Parser::GateargContext>(i);
}


size_t OQASM2Parser::MeasureContext::getRuleIndex() const {
  return OQASM2Parser::RuleMeasure;
}

void OQASM2Parser::MeasureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMeasure(this);
}

void OQASM2Parser::MeasureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMeasure(this);
}

OQASM2Parser::MeasureContext* OQASM2Parser::measure() {
  MeasureContext *_localctx = _tracker.createInstance<MeasureContext>(_ctx, getState());
  enterRule(_localctx, 68, OQASM2Parser::RuleMeasure);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(330);
    match(OQASM2Parser::MEASURE);
    setState(333);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      setState(331);
      dynamic_cast<MeasureContext *>(_localctx)->qbit = gatearg();
      break;
    }

    case 2: {
      setState(332);
      qregister();
      break;
    }

    }
    setState(335);
    match(OQASM2Parser::T__25);
    setState(338);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      setState(336);
      dynamic_cast<MeasureContext *>(_localctx)->cbit = gatearg();
      break;
    }

    case 2: {
      setState(337);
      cregister();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReesetContext ------------------------------------------------------------------

OQASM2Parser::ReesetContext::ReesetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OQASM2Parser::ReesetContext::RESET() {
  return getToken(OQASM2Parser::RESET, 0);
}

OQASM2Parser::GateargContext* OQASM2Parser::ReesetContext::gatearg() {
  return getRuleContext<OQASM2Parser::GateargContext>(0);
}

OQASM2Parser::QregisterContext* OQASM2Parser::ReesetContext::qregister() {
  return getRuleContext<OQASM2Parser::QregisterContext>(0);
}

OQASM2Parser::CregisterContext* OQASM2Parser::ReesetContext::cregister() {
  return getRuleContext<OQASM2Parser::CregisterContext>(0);
}


size_t OQASM2Parser::ReesetContext::getRuleIndex() const {
  return OQASM2Parser::RuleReeset;
}

void OQASM2Parser::ReesetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReeset(this);
}

void OQASM2Parser::ReesetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReeset(this);
}

OQASM2Parser::ReesetContext* OQASM2Parser::reeset() {
  ReesetContext *_localctx = _tracker.createInstance<ReesetContext>(_ctx, getState());
  enterRule(_localctx, 70, OQASM2Parser::RuleReeset);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(340);
    match(OQASM2Parser::RESET);
    setState(344);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      setState(341);
      gatearg();
      break;
    }

    case 2: {
      setState(342);
      qregister();
      break;
    }

    case 3: {
      setState(343);
      cregister();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BarrierContext ------------------------------------------------------------------

OQASM2Parser::BarrierContext::BarrierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OQASM2Parser::BarrierContext::BARRIER() {
  return getToken(OQASM2Parser::BARRIER, 0);
}

OQASM2Parser::GatearglistContext* OQASM2Parser::BarrierContext::gatearglist() {
  return getRuleContext<OQASM2Parser::GatearglistContext>(0);
}


size_t OQASM2Parser::BarrierContext::getRuleIndex() const {
  return OQASM2Parser::RuleBarrier;
}

void OQASM2Parser::BarrierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBarrier(this);
}

void OQASM2Parser::BarrierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBarrier(this);
}

OQASM2Parser::BarrierContext* OQASM2Parser::barrier() {
  BarrierContext *_localctx = _tracker.createInstance<BarrierContext>(_ctx, getState());
  enterRule(_localctx, 72, OQASM2Parser::RuleBarrier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(346);
    match(OQASM2Parser::BARRIER);
    setState(347);
    gatearglist();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdContext ------------------------------------------------------------------

OQASM2Parser::IdContext::IdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OQASM2Parser::IdContext::ID() {
  return getToken(OQASM2Parser::ID, 0);
}


size_t OQASM2Parser::IdContext::getRuleIndex() const {
  return OQASM2Parser::RuleId;
}

void OQASM2Parser::IdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterId(this);
}

void OQASM2Parser::IdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitId(this);
}

OQASM2Parser::IdContext* OQASM2Parser::id() {
  IdContext *_localctx = _tracker.createInstance<IdContext>(_ctx, getState());
  enterRule(_localctx, 74, OQASM2Parser::RuleId);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(349);
    match(OQASM2Parser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RealContext ------------------------------------------------------------------

OQASM2Parser::RealContext::RealContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OQASM2Parser::RealContext::REAL() {
  return getToken(OQASM2Parser::REAL, 0);
}


size_t OQASM2Parser::RealContext::getRuleIndex() const {
  return OQASM2Parser::RuleReal;
}

void OQASM2Parser::RealContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReal(this);
}

void OQASM2Parser::RealContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReal(this);
}

OQASM2Parser::RealContext* OQASM2Parser::real() {
  RealContext *_localctx = _tracker.createInstance<RealContext>(_ctx, getState());
  enterRule(_localctx, 76, OQASM2Parser::RuleReal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(351);
    match(OQASM2Parser::REAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

OQASM2Parser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OQASM2Parser::StringContext::STRING() {
  return getToken(OQASM2Parser::STRING, 0);
}


size_t OQASM2Parser::StringContext::getRuleIndex() const {
  return OQASM2Parser::RuleString;
}

void OQASM2Parser::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}

void OQASM2Parser::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OQASM2Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
}

OQASM2Parser::StringContext* OQASM2Parser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 78, OQASM2Parser::RuleString);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(353);
    match(OQASM2Parser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool OQASM2Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 29: return expSempred(dynamic_cast<ExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool OQASM2Parser::expSempred(ExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 8);
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> OQASM2Parser::_decisionToDFA;
atn::PredictionContextCache OQASM2Parser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN OQASM2Parser::_atn;
std::vector<uint16_t> OQASM2Parser::_serializedATN;

std::vector<std::string> OQASM2Parser::_ruleNames = {
  "mainprog", "program", "line", "statement", "comment", "include", "filename", 
  "regdecl", "qregister", "cregister", "registersize", "gatedecl", "gatename", 
  "gatearglist", "gatearg", "gatebody", "gateprog", "gateline", "paramlist", 
  "param", "opaque", "opaquename", "opaquearglist", "opaquearg", "qop", 
  "uop", "conditional", "action", "explist", "exp", "unaryop", "qreg", "creg", 
  "gate", "measure", "reeset", "barrier", "id", "real", "string"
};

std::vector<std::string> OQASM2Parser::_literalNames = {
  "", "';'", "'include'", "'['", "']'", "'('", "')'", "','", "'{'", "'}'", 
  "'U'", "'CX'", "'if'", "'=='", "'pi'", "'+'", "'-'", "'*'", "'/'", "'^'", 
  "'sin'", "'cos'", "'tan'", "'exp'", "'ln'", "'sqrt'", "'->'", "", "'qreg'", 
  "'creg'", "'gate'", "'measure'", "'reset'", "'barrier'", "", "'opaque'"
};

std::vector<std::string> OQASM2Parser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "COMMENT", "QREG", "CREG", "GATE", 
  "MEASURE", "RESET", "BARRIER", "OPENQASM", "OPAQUE", "ID", "REAL", "INT", 
  "STRING", "EOL", "WS"
};

dfa::Vocabulary OQASM2Parser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> OQASM2Parser::_tokenNames;

OQASM2Parser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2b, 0x166, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x3, 0x2, 0x7, 0x2, 0x54, 0xa, 0x2, 0xc, 0x2, 
    0xe, 0x2, 0x57, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x5, 0x2, 0x5e, 0xa, 0x2, 0x3, 0x3, 0x6, 0x3, 0x61, 0xa, 0x3, 0xd, 
    0x3, 0xe, 0x3, 0x62, 0x3, 0x4, 0x6, 0x4, 0x66, 0xa, 0x4, 0xd, 0x4, 0xe, 
    0x4, 0x67, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x6, 0x4, 0x6e, 0xa, 
    0x4, 0xd, 0x4, 0xe, 0x4, 0x6f, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x74, 0xa, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 
    0x5, 0x83, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x93, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x9b, 0xa, 0xa, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xa3, 0xa, 
    0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 
    0xd, 0xab, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 
    0xb1, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xb5, 0xa, 0xe, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xba, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xc2, 0xa, 0x10, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x7, 0x12, 0xc9, 
    0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0xcc, 0xb, 0x12, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xd4, 0xa, 0x14, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0xe0, 0xa, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x5, 0x17, 0xe4, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x5, 0x18, 0xe9, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 
    0xf4, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0xf9, 0xa, 
    0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 
    0x1b, 0x107, 0xa, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x10b, 0xa, 
    0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x7, 0x1e, 0x11a, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x11d, 0xb, 
    0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x12f, 0xa, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 0x140, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 
    0x143, 0xb, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 
    0x24, 0x150, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 
    0x155, 0xa, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 
    0x15b, 0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x2, 0x3, 0x3c, 
    0x2a, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 
    0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 
    0x4a, 0x4c, 0x4e, 0x50, 0x2, 0x3, 0x3, 0x2, 0x16, 0x1b, 0x2, 0x16c, 
    0x2, 0x55, 0x3, 0x2, 0x2, 0x2, 0x4, 0x60, 0x3, 0x2, 0x2, 0x2, 0x6, 0x73, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x82, 0x3, 0x2, 0x2, 0x2, 0xa, 0x84, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x86, 0x3, 0x2, 0x2, 0x2, 0xe, 0x8a, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x92, 0x3, 0x2, 0x2, 0x2, 0x12, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0xa2, 0x3, 0x2, 0x2, 0x2, 0x16, 0xa4, 0x3, 0x2, 0x2, 0x2, 0x18, 0xa6, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0xb4, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xb6, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x20, 0xc3, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0xca, 0x3, 0x2, 0x2, 0x2, 0x24, 0xcd, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0xd0, 0x3, 0x2, 0x2, 0x2, 0x28, 0xd5, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0xe5, 0x3, 0x2, 0x2, 0x2, 0x30, 0xea, 0x3, 0x2, 0x2, 0x2, 0x32, 0xf3, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x36, 0x10c, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0x114, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x116, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x144, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x146, 0x3, 0x2, 0x2, 0x2, 0x42, 0x148, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x46, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x48, 
    0x156, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x15f, 
    0x3, 0x2, 0x2, 0x2, 0x4e, 0x161, 0x3, 0x2, 0x2, 0x2, 0x50, 0x163, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x54, 0x5, 0xa, 0x6, 0x2, 0x53, 0x52, 0x3, 0x2, 
    0x2, 0x2, 0x54, 0x57, 0x3, 0x2, 0x2, 0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 
    0x2, 0x55, 0x56, 0x3, 0x2, 0x2, 0x2, 0x56, 0x58, 0x3, 0x2, 0x2, 0x2, 
    0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x7, 0x24, 0x2, 0x2, 0x59, 
    0x5a, 0x5, 0x4e, 0x28, 0x2, 0x5a, 0x5b, 0x7, 0x3, 0x2, 0x2, 0x5b, 0x5d, 
    0x7, 0x2a, 0x2, 0x2, 0x5c, 0x5e, 0x5, 0x4, 0x3, 0x2, 0x5d, 0x5c, 0x3, 
    0x2, 0x2, 0x2, 0x5d, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x5f, 0x61, 0x5, 0x6, 0x4, 0x2, 0x60, 0x5f, 0x3, 0x2, 0x2, 
    0x2, 0x61, 0x62, 0x3, 0x2, 0x2, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 
    0x62, 0x63, 0x3, 0x2, 0x2, 0x2, 0x63, 0x5, 0x3, 0x2, 0x2, 0x2, 0x64, 
    0x66, 0x5, 0x8, 0x5, 0x2, 0x65, 0x64, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 
    0x3, 0x2, 0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x3, 
    0x2, 0x2, 0x2, 0x68, 0x69, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x7, 0x2a, 
    0x2, 0x2, 0x6a, 0x74, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x74, 0x5, 0xa, 0x6, 
    0x2, 0x6c, 0x6e, 0x5, 0xc, 0x7, 0x2, 0x6d, 0x6c, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6f, 
    0x70, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 
    0x7, 0x2a, 0x2, 0x2, 0x72, 0x74, 0x3, 0x2, 0x2, 0x2, 0x73, 0x65, 0x3, 
    0x2, 0x2, 0x2, 0x73, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x73, 0x6d, 0x3, 0x2, 
    0x2, 0x2, 0x74, 0x7, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x5, 0x10, 0x9, 
    0x2, 0x76, 0x77, 0x7, 0x3, 0x2, 0x2, 0x77, 0x83, 0x3, 0x2, 0x2, 0x2, 
    0x78, 0x83, 0x5, 0x18, 0xd, 0x2, 0x79, 0x7a, 0x5, 0x2a, 0x16, 0x2, 0x7a, 
    0x7b, 0x7, 0x3, 0x2, 0x2, 0x7b, 0x83, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 
    0x5, 0x32, 0x1a, 0x2, 0x7d, 0x7e, 0x7, 0x3, 0x2, 0x2, 0x7e, 0x83, 0x3, 
    0x2, 0x2, 0x2, 0x7f, 0x80, 0x5, 0x36, 0x1c, 0x2, 0x80, 0x81, 0x7, 0x3, 
    0x2, 0x2, 0x81, 0x83, 0x3, 0x2, 0x2, 0x2, 0x82, 0x75, 0x3, 0x2, 0x2, 
    0x2, 0x82, 0x78, 0x3, 0x2, 0x2, 0x2, 0x82, 0x79, 0x3, 0x2, 0x2, 0x2, 
    0x82, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x82, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x83, 
    0x9, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x7, 0x1d, 0x2, 0x2, 0x85, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x7, 0x4, 0x2, 0x2, 0x87, 0x88, 0x5, 
    0xe, 0x8, 0x2, 0x88, 0x89, 0x7, 0x3, 0x2, 0x2, 0x89, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0x8a, 0x8b, 0x5, 0x50, 0x29, 0x2, 0x8b, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x8c, 0x8d, 0x5, 0x40, 0x21, 0x2, 0x8d, 0x8e, 0x5, 0x12, 0xa, 0x2, 
    0x8e, 0x93, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x5, 0x42, 0x22, 0x2, 0x90, 
    0x91, 0x5, 0x14, 0xb, 0x2, 0x91, 0x93, 0x3, 0x2, 0x2, 0x2, 0x92, 0x8c, 
    0x3, 0x2, 0x2, 0x2, 0x92, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x93, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x94, 0x95, 0x5, 0x4c, 0x27, 0x2, 0x95, 0x96, 0x7, 0x5, 
    0x2, 0x2, 0x96, 0x97, 0x5, 0x16, 0xc, 0x2, 0x97, 0x98, 0x7, 0x6, 0x2, 
    0x2, 0x98, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9b, 0x5, 0x4c, 0x27, 0x2, 
    0x9a, 0x94, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9b, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x5, 0x4c, 0x27, 0x2, 0x9d, 0x9e, 
    0x7, 0x5, 0x2, 0x2, 0x9e, 0x9f, 0x5, 0x16, 0xc, 0x2, 0x9f, 0xa0, 0x7, 
    0x6, 0x2, 0x2, 0xa0, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa3, 0x5, 0x4c, 
    0x27, 0x2, 0xa2, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa1, 0x3, 0x2, 0x2, 
    0x2, 0xa3, 0x15, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x7, 0x28, 0x2, 0x2, 
    0xa5, 0x17, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x5, 0x44, 0x23, 0x2, 0xa7, 
    0xa8, 0x5, 0x1a, 0xe, 0x2, 0xa8, 0xaa, 0x5, 0x1c, 0xf, 0x2, 0xa9, 0xab, 
    0x5, 0x20, 0x11, 0x2, 0xaa, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x3, 
    0x2, 0x2, 0x2, 0xab, 0x19, 0x3, 0x2, 0x2, 0x2, 0xac, 0xb5, 0x5, 0x4c, 
    0x27, 0x2, 0xad, 0xae, 0x5, 0x4c, 0x27, 0x2, 0xae, 0xb0, 0x7, 0x7, 0x2, 
    0x2, 0xaf, 0xb1, 0x5, 0x26, 0x14, 0x2, 0xb0, 0xaf, 0x3, 0x2, 0x2, 0x2, 
    0xb0, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb2, 
    0xb3, 0x7, 0x8, 0x2, 0x2, 0xb3, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xac, 
    0x3, 0x2, 0x2, 0x2, 0xb4, 0xad, 0x3, 0x2, 0x2, 0x2, 0xb5, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0xb6, 0xb9, 0x5, 0x1e, 0x10, 0x2, 0xb7, 0xb8, 0x7, 0x9, 
    0x2, 0x2, 0xb8, 0xba, 0x5, 0x1c, 0xf, 0x2, 0xb9, 0xb7, 0x3, 0x2, 0x2, 
    0x2, 0xb9, 0xba, 0x3, 0x2, 0x2, 0x2, 0xba, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0xbb, 0xbc, 0x5, 0x4c, 0x27, 0x2, 0xbc, 0xbd, 0x7, 0x5, 0x2, 0x2, 0xbd, 
    0xbe, 0x7, 0x28, 0x2, 0x2, 0xbe, 0xbf, 0x7, 0x6, 0x2, 0x2, 0xbf, 0xc2, 
    0x3, 0x2, 0x2, 0x2, 0xc0, 0xc2, 0x5, 0x4c, 0x27, 0x2, 0xc1, 0xbb, 0x3, 
    0x2, 0x2, 0x2, 0xc1, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc2, 0x1f, 0x3, 0x2, 
    0x2, 0x2, 0xc3, 0xc4, 0x7, 0xa, 0x2, 0x2, 0xc4, 0xc5, 0x5, 0x22, 0x12, 
    0x2, 0xc5, 0xc6, 0x7, 0xb, 0x2, 0x2, 0xc6, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0xc7, 0xc9, 0x5, 0x24, 0x13, 0x2, 0xc8, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc9, 
    0xcc, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 
    0x3, 0x2, 0x2, 0x2, 0xcb, 0x23, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xca, 0x3, 
    0x2, 0x2, 0x2, 0xcd, 0xce, 0x5, 0x34, 0x1b, 0x2, 0xce, 0xcf, 0x7, 0x3, 
    0x2, 0x2, 0xcf, 0x25, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd3, 0x5, 0x28, 0x15, 
    0x2, 0xd1, 0xd2, 0x7, 0x9, 0x2, 0x2, 0xd2, 0xd4, 0x5, 0x26, 0x14, 0x2, 
    0xd3, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd4, 
    0x27, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 0x5, 0x4c, 0x27, 0x2, 0xd6, 0x29, 
    0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x7, 0x25, 0x2, 0x2, 0xd8, 0xd9, 0x5, 
    0x2c, 0x17, 0x2, 0xd9, 0xda, 0x5, 0x2e, 0x18, 0x2, 0xda, 0x2b, 0x3, 
    0x2, 0x2, 0x2, 0xdb, 0xe4, 0x5, 0x4c, 0x27, 0x2, 0xdc, 0xdd, 0x5, 0x4c, 
    0x27, 0x2, 0xdd, 0xdf, 0x7, 0x7, 0x2, 0x2, 0xde, 0xe0, 0x5, 0x26, 0x14, 
    0x2, 0xdf, 0xde, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x3, 0x2, 0x2, 0x2, 
    0xe0, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 0x7, 0x8, 0x2, 0x2, 0xe2, 
    0xe4, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xdc, 
    0x3, 0x2, 0x2, 0x2, 0xe4, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe8, 0x5, 
    0x30, 0x19, 0x2, 0xe6, 0xe7, 0x7, 0x9, 0x2, 0x2, 0xe7, 0xe9, 0x5, 0x2e, 
    0x18, 0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0x3, 0x2, 0x2, 
    0x2, 0xe9, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 0x5, 0x4c, 0x27, 0x2, 
    0xeb, 0xec, 0x7, 0x5, 0x2, 0x2, 0xec, 0xed, 0x7, 0x28, 0x2, 0x2, 0xed, 
    0xee, 0x7, 0x6, 0x2, 0x2, 0xee, 0x31, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf4, 
    0x5, 0x34, 0x1b, 0x2, 0xf0, 0xf4, 0x5, 0x48, 0x25, 0x2, 0xf1, 0xf4, 
    0x5, 0x46, 0x24, 0x2, 0xf2, 0xf4, 0x5, 0x4a, 0x26, 0x2, 0xf3, 0xef, 
    0x3, 0x2, 0x2, 0x2, 0xf3, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf1, 0x3, 
    0x2, 0x2, 0x2, 0xf3, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf4, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0xf5, 0xf6, 0x7, 0xc, 0x2, 0x2, 0xf6, 0xf8, 0x7, 0x7, 0x2, 
    0x2, 0xf7, 0xf9, 0x5, 0x3a, 0x1e, 0x2, 0xf8, 0xf7, 0x3, 0x2, 0x2, 0x2, 
    0xf8, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfa, 
    0xfb, 0x7, 0x8, 0x2, 0x2, 0xfb, 0x10b, 0x5, 0x1e, 0x10, 0x2, 0xfc, 0xfd, 
    0x7, 0xd, 0x2, 0x2, 0xfd, 0xfe, 0x5, 0x1e, 0x10, 0x2, 0xfe, 0xff, 0x7, 
    0x9, 0x2, 0x2, 0xff, 0x100, 0x5, 0x1e, 0x10, 0x2, 0x100, 0x10b, 0x3, 
    0x2, 0x2, 0x2, 0x101, 0x106, 0x5, 0x1a, 0xe, 0x2, 0x102, 0x103, 0x7, 
    0x7, 0x2, 0x2, 0x103, 0x104, 0x5, 0x3a, 0x1e, 0x2, 0x104, 0x105, 0x7, 
    0x8, 0x2, 0x2, 0x105, 0x107, 0x3, 0x2, 0x2, 0x2, 0x106, 0x102, 0x3, 
    0x2, 0x2, 0x2, 0x106, 0x107, 0x3, 0x2, 0x2, 0x2, 0x107, 0x108, 0x3, 
    0x2, 0x2, 0x2, 0x108, 0x109, 0x5, 0x1c, 0xf, 0x2, 0x109, 0x10b, 0x3, 
    0x2, 0x2, 0x2, 0x10a, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x10a, 0xfc, 0x3, 0x2, 
    0x2, 0x2, 0x10a, 0x101, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x35, 0x3, 0x2, 0x2, 
    0x2, 0x10c, 0x10d, 0x7, 0xe, 0x2, 0x2, 0x10d, 0x10e, 0x7, 0x7, 0x2, 
    0x2, 0x10e, 0x10f, 0x5, 0x4c, 0x27, 0x2, 0x10f, 0x110, 0x7, 0xf, 0x2, 
    0x2, 0x110, 0x111, 0x7, 0x28, 0x2, 0x2, 0x111, 0x112, 0x7, 0x8, 0x2, 
    0x2, 0x112, 0x113, 0x5, 0x38, 0x1d, 0x2, 0x113, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x114, 0x115, 0x5, 0x32, 0x1a, 0x2, 0x115, 0x39, 0x3, 0x2, 0x2, 
    0x2, 0x116, 0x11b, 0x5, 0x3c, 0x1f, 0x2, 0x117, 0x118, 0x7, 0x9, 0x2, 
    0x2, 0x118, 0x11a, 0x5, 0x3c, 0x1f, 0x2, 0x119, 0x117, 0x3, 0x2, 0x2, 
    0x2, 0x11a, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x119, 0x3, 0x2, 0x2, 
    0x2, 0x11b, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x11d, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11f, 0x8, 0x1f, 0x1, 0x2, 
    0x11f, 0x12f, 0x5, 0x4e, 0x28, 0x2, 0x120, 0x12f, 0x7, 0x28, 0x2, 0x2, 
    0x121, 0x12f, 0x7, 0x10, 0x2, 0x2, 0x122, 0x12f, 0x5, 0x4c, 0x27, 0x2, 
    0x123, 0x124, 0x7, 0x12, 0x2, 0x2, 0x124, 0x12f, 0x5, 0x3c, 0x1f, 0x6, 
    0x125, 0x126, 0x7, 0x7, 0x2, 0x2, 0x126, 0x127, 0x5, 0x3c, 0x1f, 0x2, 
    0x127, 0x128, 0x7, 0x8, 0x2, 0x2, 0x128, 0x12f, 0x3, 0x2, 0x2, 0x2, 
    0x129, 0x12a, 0x5, 0x3e, 0x20, 0x2, 0x12a, 0x12b, 0x7, 0x7, 0x2, 0x2, 
    0x12b, 0x12c, 0x5, 0x3c, 0x1f, 0x2, 0x12c, 0x12d, 0x7, 0x8, 0x2, 0x2, 
    0x12d, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x11e, 0x3, 0x2, 0x2, 0x2, 
    0x12e, 0x120, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x121, 0x3, 0x2, 0x2, 0x2, 
    0x12e, 0x122, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x123, 0x3, 0x2, 0x2, 0x2, 
    0x12e, 0x125, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x129, 0x3, 0x2, 0x2, 0x2, 
    0x12f, 0x141, 0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 0xc, 0xa, 0x2, 0x2, 
    0x131, 0x132, 0x7, 0x11, 0x2, 0x2, 0x132, 0x140, 0x5, 0x3c, 0x1f, 0xb, 
    0x133, 0x134, 0xc, 0x9, 0x2, 0x2, 0x134, 0x135, 0x7, 0x12, 0x2, 0x2, 
    0x135, 0x140, 0x5, 0x3c, 0x1f, 0xa, 0x136, 0x137, 0xc, 0x8, 0x2, 0x2, 
    0x137, 0x138, 0x7, 0x13, 0x2, 0x2, 0x138, 0x140, 0x5, 0x3c, 0x1f, 0x9, 
    0x139, 0x13a, 0xc, 0x7, 0x2, 0x2, 0x13a, 0x13b, 0x7, 0x14, 0x2, 0x2, 
    0x13b, 0x140, 0x5, 0x3c, 0x1f, 0x8, 0x13c, 0x13d, 0xc, 0x5, 0x2, 0x2, 
    0x13d, 0x13e, 0x7, 0x15, 0x2, 0x2, 0x13e, 0x140, 0x5, 0x3c, 0x1f, 0x6, 
    0x13f, 0x130, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x133, 0x3, 0x2, 0x2, 0x2, 
    0x13f, 0x136, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x139, 0x3, 0x2, 0x2, 0x2, 
    0x13f, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x140, 0x143, 0x3, 0x2, 0x2, 0x2, 
    0x141, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x3, 0x2, 0x2, 0x2, 
    0x142, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x143, 0x141, 0x3, 0x2, 0x2, 0x2, 0x144, 
    0x145, 0x9, 0x2, 0x2, 0x2, 0x145, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 
    0x7, 0x1e, 0x2, 0x2, 0x147, 0x41, 0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 
    0x7, 0x1f, 0x2, 0x2, 0x149, 0x43, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 
    0x7, 0x20, 0x2, 0x2, 0x14b, 0x45, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14f, 
    0x7, 0x21, 0x2, 0x2, 0x14d, 0x150, 0x5, 0x1e, 0x10, 0x2, 0x14e, 0x150, 
    0x5, 0x12, 0xa, 0x2, 0x14f, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x14e, 
    0x3, 0x2, 0x2, 0x2, 0x150, 0x151, 0x3, 0x2, 0x2, 0x2, 0x151, 0x154, 
    0x7, 0x1c, 0x2, 0x2, 0x152, 0x155, 0x5, 0x1e, 0x10, 0x2, 0x153, 0x155, 
    0x5, 0x14, 0xb, 0x2, 0x154, 0x152, 0x3, 0x2, 0x2, 0x2, 0x154, 0x153, 
    0x3, 0x2, 0x2, 0x2, 0x155, 0x47, 0x3, 0x2, 0x2, 0x2, 0x156, 0x15a, 0x7, 
    0x22, 0x2, 0x2, 0x157, 0x15b, 0x5, 0x1e, 0x10, 0x2, 0x158, 0x15b, 0x5, 
    0x12, 0xa, 0x2, 0x159, 0x15b, 0x5, 0x14, 0xb, 0x2, 0x15a, 0x157, 0x3, 
    0x2, 0x2, 0x2, 0x15a, 0x158, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x159, 0x3, 
    0x2, 0x2, 0x2, 0x15b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15d, 0x7, 0x23, 
    0x2, 0x2, 0x15d, 0x15e, 0x5, 0x1c, 0xf, 0x2, 0x15e, 0x4b, 0x3, 0x2, 
    0x2, 0x2, 0x15f, 0x160, 0x7, 0x26, 0x2, 0x2, 0x160, 0x4d, 0x3, 0x2, 
    0x2, 0x2, 0x161, 0x162, 0x7, 0x27, 0x2, 0x2, 0x162, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0x163, 0x164, 0x7, 0x29, 0x2, 0x2, 0x164, 0x51, 0x3, 0x2, 
    0x2, 0x2, 0x21, 0x55, 0x5d, 0x62, 0x67, 0x6f, 0x73, 0x82, 0x92, 0x9a, 
    0xa2, 0xaa, 0xb0, 0xb4, 0xb9, 0xc1, 0xca, 0xd3, 0xdf, 0xe3, 0xe8, 0xf3, 
    0xf8, 0x106, 0x10a, 0x11b, 0x12e, 0x13f, 0x141, 0x14f, 0x154, 0x15a, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

OQASM2Parser::Initializer OQASM2Parser::_init;
