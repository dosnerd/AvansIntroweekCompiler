//
// Created by david on 11-3-19.
//

#include <sstream>
#include "Statements/DivideStatement.h"

Compiler::Factory::StatementCreatorInstance
        <Compiler::Statements::DivideStatement> Compiler::Statements::DivideStatement::sCreator("DIVIDE_BY");

Compiler::Statements::DivideStatement::DivideStatement(int number) {

}

Compiler::Statements::DivideStatement::DivideStatement(std::list<std::string> args, unsigned iLine) {
    if (args.size() != 1)
        throw INVALID_COUNT_PARAMS;

    std::istringstream iss(args.front());
    if (!(iss >> m_number)) {
        m_param = args.front();
    } else {
        m_param = "";
    }
}

bool Compiler::Statements::DivideStatement::Execute() {
    Memory &memory = GetMemory();
    int value = memory.GetStack();

    if (!m_param.empty()){
        m_number = memory.GetHeap(m_param);
    }

    if (m_number == 0)
        throw DIVIDE_BY_ZERO;

    value /= m_number;
    memory.SetStack(value);

    return true;
}
