#include <utility>

//
// Created by david on 4-3-19.
//

#ifndef COMPILER_STATEMENTCREATOR_H
#define COMPILER_STATEMENTCREATOR_H


#include <Statements/Statement.h>
#include "StatementFactory.h"

namespace Compiler {
    namespace Factory {
        class StatementCreator {
        public:
            explicit                        StatementCreator(std::string name) { StatementFactory::GetInstance().AddCreator(std::move(name), this); };
            virtual                         ~StatementCreator() = default;

        public:
            virtual Statements::Statement   *Create(std::list<std::string> params, unsigned iLine) = 0;
        };
    };
};


#endif //COMPILER_STATEMENTCREATOR_H
