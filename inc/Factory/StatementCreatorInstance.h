//
// Created by david on 4-3-19.
//

#ifndef COMPILER_STATEMENTCREATORINSTANCE_H
#define COMPILER_STATEMENTCREATORINSTANCE_H


#include "StatementCreator.h"

namespace Compiler {
    namespace Factory {

        template <class T>
        class StatementCreatorInstance : public StatementCreator {
        public:
            explicit                    StatementCreatorInstance(std::string name) : StatementCreator(name) { };
                                        ~StatementCreatorInstance() override = default;

        public:
            Statements::Statement       *Create(std::list<std::string> params) override { return new T(params); };
        };
    };
};


#endif //COMPILER_STATEMENTCREATORINSTANCE_H
