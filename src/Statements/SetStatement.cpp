//
// Created by david on 21-2-19.
//

#include <Statements/SetStatement.h>
#include <sstream>

#include "../../inc/Statements/SetStatement.h"

Compiler::Factory::StatementCreatorInstance
        <Compiler::Statements::SetStatement> Compiler::Statements::SetStatement::sCreator("SET");

Compiler::Statements::SetStatement::SetStatement(std::list<std::string> args) {
    if (args.empty() || args.size() > 2)
        throw INVALID_COUNT_PARAMS;

    m_var = args.front();
    m_fromStack = args.size() == 1;

    args.pop_front();
    if (args.size() == 1) {
        std::istringstream iss(args.front());
        if (!(iss >> m_value)) {
            throw INVALID_PARAM(2);
        }
    }
}

Compiler::Statements::SetStatement::SetStatement(std::string var)
        : m_var(std::move(var)), m_fromStack(true) {
}

Compiler::Statements::SetStatement::SetStatement(int value, std::string var)
        : m_var(std::move(var)), m_value(value), m_fromStack(false) {
}

bool Compiler::Statements::SetStatement::Execute() {
    Memory &memory = GetMemory();
    int value = m_fromStack ? memory.GetStack() : m_value;

    return memory.SetHeap(m_var, value);
}
