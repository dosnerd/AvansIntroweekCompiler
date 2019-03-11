//
// Created by david on 4-3-19.
//

#ifndef COMPILER_STATEMENTFACTORY_H
#define COMPILER_STATEMENTFACTORY_H


#include <Statements/Statement.h>
#include <list>
#include <map>

namespace Compiler {
    namespace Factory {
        class StatementCreator;

        class StatementFactory {
        public:
            static StatementFactory&    GetInstance();


#ifdef TESTING
        public:
#else
        private:
#endif
            explicit                    StatementFactory() = default;
                                        ~StatementFactory() = default;

        public:
            Statements::Statement       *CreateStatement(std::string command, std::list<std::string> params, unsigned iLine);
            void                        AddCreator(std::string command, StatementCreator *creator);
            void                        RemoveCreator(std::string command);

        private:
            std::map<std::string, StatementCreator *>
                                        m_registered;

        private:
            bool                        Exists(std::string command);
        };
    };
};


#endif //COMPILER_STATEMENTFACTORY_H
