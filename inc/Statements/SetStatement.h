//
// Created by david on 21-2-19.
//

#ifndef COMPILER_SETSTATEMENT_H
#define COMPILER_SETSTATEMENT_H


#include <list>
#include <Factory/StatementCreatorInstance.h>
#include "Statement.h"

namespace Compiler {
    namespace Statements {
        class SetStatement : public Statement {
        public:
            explicit                    SetStatement(std::list<std::string> args, unsigned iLine);
            explicit                    SetStatement(std::string var);
                                        SetStatement(int value, std::string var);

        public:
            bool                        Execute() override;

        private:
            static Factory::StatementCreatorInstance<SetStatement>
                                        sCreator;

        private:
            std::string                 m_var;
            int                         m_value;
            bool                        m_fromStack;
        };
    };
};


#endif //COMPILER_SETSTATEMENT_H
