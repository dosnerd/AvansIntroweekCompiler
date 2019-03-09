//
// Created by david on 9-3-19.
//

#ifndef COMPILER_COMPILER_H
#define COMPILER_COMPILER_H


#include <string>
#include <list>
#include <Statements/Statement.h>

#define RUN_SUCCEED             0

namespace Compiler {
    class Compiler {
    public:
        explicit                                Compiler();
                                                ~Compiler() = default;

    public:
        std::string                             Compile(std::string code);
        unsigned long                           Run();
        std::string                             RunTimeErrorReport(std::string code);

    private:
        std::list<Statements::Statement *>      m_program;
        std::string                             m_error;
        unsigned long                           m_errorLine;

    private:
        std::string                             CompileLine(std::string &line);
        std::list<std::string>                  SplitLines(std::string &code);
        std::list<std::string>                  SplitParams(std::string &line);
    };
};


#endif //COMPILER_COMPILER_H
