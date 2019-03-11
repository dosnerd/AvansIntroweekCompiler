//
// Created by david on 11-3-19.
//

#ifndef COMPILER_TIMESSTATEMENT_H
#define COMPILER_TIMESSTATEMENT_H

#include <Factory/StatementCreatorInstance.h>
#include "Statement.h"
#include <list>

namespace Compiler {
    namespace Statements {
        class TimesStatement : public Statement {
        public:
            explicit                    TimesStatement(std::list<std::string> args, unsigned iLine);
                                        ~TimesStatement() override = default;

        public:
            bool                        Execute() override;

        private:
            static Factory::StatementCreatorInstance<TimesStatement>
                                        sCreator;

        private:
            int                         m_number;
            std::string                 m_param;
        };
    };
};


#endif //COMPILER_TIMESSTATEMENT_H
