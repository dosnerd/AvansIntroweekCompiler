//
// Created by david on 21-2-19.
//

#ifndef COMPILER_ADDSTATEMENT_H
#define COMPILER_ADDSTATEMENT_H


#include <list>
#include <Factory/StatementCreatorInstance.h>
#include "Statement.h"

namespace Compiler {
    namespace Statements {
        class AddStatement : public Statement {
        public:
            explicit                    AddStatement(int number);
            explicit                    AddStatement(std::list<std::string> args);
                                        ~AddStatement() override = default;

        public:
            bool                        Execute() override;

        private:
            static Factory::StatementCreatorInstance<AddStatement>
                                        sCreator;

        private:
            int                         m_number;
        };
    }
}


#endif //COMPILER_ADDSTATEMENT_H
