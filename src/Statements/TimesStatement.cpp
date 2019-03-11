//
// Created by david on 11-3-19.
//

#include <Statements/TimesStatement.h>
#include <sstream>

Compiler::Factory::StatementCreatorInstance
        <Compiler::Statements::TimesStatement> Compiler::Statements::TimesStatement::sCreator("TIMES");

Compiler::Statements::TimesStatement::TimesStatement(std::list<std::string> args, unsigned iLine) {
    if (args.size() != 1)
        throw INVALID_COUNT_PARAMS;

    std::istringstream iss(args.front());
    if (!(iss >> m_number)) {
        m_param = args.front();
    } else {
        m_param = "";
    }
}

bool Compiler::Statements::TimesStatement::Execute() {
    Memory &memory = GetMemory();
    int value = memory.GetStack();

    if (!m_param.empty()){
        m_number = memory.GetHeap(m_param);
    }

    value *= m_number;
    memory.SetStack(value);
    return true;
}
