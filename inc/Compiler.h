//
// Created by david on 9-3-19.
//

#ifndef COMPILER_COMPILER_H
#define COMPILER_COMPILER_H


#include <string>
#include <list>
#include <vector>
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
        std::vector<Statements::Statement *>    m_program;
        std::string                             m_error;

    private:
        std::string                             CompileLine(std::string &line, unsigned iLine);
        std::list<std::string>                  SplitLines(std::string &code);
        std::list<std::string>                  SplitParams(std::string &line);
        std::string                             Replace(std::string str, std::string from, std::string to);
    };
};


#endif //COMPILER_COMPILER_H
