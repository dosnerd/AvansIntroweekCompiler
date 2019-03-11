//
// Created by david on 21-2-19.
//

#include "../../inc/Statements/GetStatement.h"

Compiler::Factory::StatementCreatorInstance
        <Compiler::Statements::GetStatement> Compiler::Statements::GetStatement::sCreator("GET");

Compiler::Statements::GetStatement::GetStatement(std::string var)
    : m_var(std::move(var))
{

}

Compiler::Statements::GetStatement::GetStatement(std::list<std::string> args, unsigned iLine) {
    if (args.size() != 1)
        throw INVALID_COUNT_PARAMS;

    m_var = args.front();
}

bool Compiler::Statements::GetStatement::Execute() {
    Memory &memory = GetMemory();
    int value;

    value = memory.GetHeap(m_var);

    memory.SetStack(value);
    return true;
}
