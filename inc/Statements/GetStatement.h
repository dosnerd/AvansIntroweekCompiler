//
// Created by david on 21-2-19.
//

#ifndef COMPILER_GETSTATEMENT_H
#define COMPILER_GETSTATEMENT_H


#include "Statement.h"
#include <list>
#include <Factory/StatementCreatorInstance.h>

namespace Compiler {
    namespace Statements {
        class GetStatement : public Statement {
        public:
            explicit                    GetStatement(std::string var);
            explicit                    GetStatement(std::list<std::string> args, unsigned iLine);
                                        ~GetStatement() override = default;

        public:
            bool                        Execute() override;

        private:
            static Factory::StatementCreatorInstance<GetStatement>
                                        sCreator;
        private:
            std::string                 m_var;
        };
    }
}


#endif //COMPILER_GETSTATEMENT_H
