//
// Created by david on 21-2-19.
//

#include <Statements/AddStatement.h>
#include <sstream>

Compiler::Factory::StatementCreatorInstance
        <Compiler::Statements::AddStatement> Compiler::Statements::AddStatement::sCreator("ADD");

Compiler::Statements::AddStatement::AddStatement(int number)
    : m_number(number)
{

}

Compiler::Statements::AddStatement::AddStatement(std::list<std::string> args, unsigned iLine) {
    if (args.size() != 1)
        throw INVALID_COUNT_PARAMS;

    std::istringstream iss(args.front());
    if (!(iss >> m_number)) {
        m_param = args.front();
    } else {
        m_param = "";
    }
}

bool Compiler::Statements::AddStatement::Execute() {
    Memory &memory = GetMemory();
    int value = memory.GetStack();

    if (!m_param.empty()){
        m_number = memory.GetHeap(m_param);
    }

    value += m_number;
    memory.SetStack(value);

    return true;
}