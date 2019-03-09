//
// Created by david on 21-2-19.
//

#include "../../inc/Statements/Statement.h"

Compiler::Statements::Statement::Statement() {
#ifdef TESTING
//    m_memory = new Memory();
    m_memory = &Memory::GetInstance();
#endif
}

Compiler::Statements::Statement::~Statement() {
}

const Compiler::Memory &Compiler::Statements::Statement::GetMemory() const {
#ifdef TESTING
    return *m_memory;
#else
    return Memory::GetInstance();
#endif
}

Compiler::Memory &Compiler::Statements::Statement::GetMemory() {
#ifdef TESTING
    return *m_memory;
#else
    return Memory::GetInstance();
#endif
}

#ifdef TESTING

void Compiler::Statements::Statement::SetMemory(Memory *memory) {
    m_memory = memory;
}

#endif
