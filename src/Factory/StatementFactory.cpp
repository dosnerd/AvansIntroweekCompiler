//
// Created by david on 4-3-19.
//

#include <Factory/StatementFactory.h>
#include "Factory/StatementCreator.h"

Compiler::Factory::StatementFactory &Compiler::Factory::StatementFactory::GetInstance() {
    static StatementFactory factory;
    return factory;
}

Compiler::Statements::Statement *
Compiler::Factory::StatementFactory::CreateStatement(std::string command, std::list<std::string> params) {
    if (!Exists(command))
        return nullptr;

    return m_registered[command]->Create(params);
}

void

Compiler::Factory::StatementFactory::AddCreator(std::string command, Compiler::Factory::StatementCreator *creator) {
    if (Exists(command))
        return;

    m_registered[command] = creator;
}

void Compiler::Factory::StatementFactory::RemoveCreator(std::string command) {
    if (!Exists(command))
        return;

    m_registered[command] = nullptr;
}

bool Compiler::Factory::StatementFactory::Exists(std::string command) {
    return m_registered.find(command) != m_registered.end();
}
