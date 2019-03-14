//
// Created by david on 11-3-19.
//

#ifndef COMPILER_DEVIDESTATEMENT_H
#define COMPILER_DEVIDESTATEMENT_H


#include "Statement.h"
#include <list>
#include <Factory/StatementCreatorInstance.h>

namespace Compiler {
    namespace Statements {
        class DivideStatement : public Statements::Statement {
        public:
            explicit                    DivideStatement(int number);
            explicit                    DivideStatement(std::list<std::string> args, unsigned iLine);
                                        ~DivideStatement() override = default;

        public:
            bool                        Execute() override;

        private:
            static Factory::StatementCreatorInstance<DivideStatement>
                    sCreator;

        private:
            int                         m_number;
            std::string                 m_param;
        };
    };
};


#endif //COMPILER_DEVIDESTATEMENT_H
