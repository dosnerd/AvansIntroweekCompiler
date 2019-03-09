//
// Created by david on 9-3-19.
//

#include <Compiler.h>
#include <sstream>
#include <regex>
#include <iostream>
#include <Factory/StatementFactory.h>

Compiler::Compiler::Compiler()
        : m_errorLine(RUN_SUCCEED), m_error("NO ERRORS") {
}

std::string Compiler::Compiler::Compile(std::string code) {
    std::stringstream feedback;
    bool containsErrors = false;
    std::list<std::string> lines = SplitLines(code);
    unsigned long lineNumber = 1;

    for (std::string line : lines) {
        std::string result = CompileLine(line);
        containsErrors = containsErrors || !result.empty();

        feedback << "Line " << lineNumber << ": " << line << " >> " << result << std::endl;
        lineNumber++;
    }

    if (containsErrors) {
        return feedback.str();
    } else if (m_program.empty())
        return "NO CODE";
    else
        return "";
}

unsigned long Compiler::Compiler::Run() {
    m_errorLine = 1;
    for (Statements::Statement *statement : m_program){
        try {
            if (!statement->Execute()) {
                m_error = "FAILED TO EXECUTE";
                return m_errorLine;
            }
        } catch (std::string &error){
            m_error = error;
            return m_errorLine;
        }

        m_errorLine++;
    }

    m_errorLine = RUN_SUCCEED;
    return m_errorLine;
}

std::string Compiler::Compiler::RunTimeErrorReport(std::string code) {
    std::stringstream feedback;
    std::list<std::string> lines = SplitLines(code);
    unsigned long lineNumber = 1;

    for (const std::string &line : lines) {
        feedback << "Line " << lineNumber << ": " << line;
        if (lineNumber == m_errorLine)
            feedback << " << " << m_error;
        feedback << std::endl;
        lineNumber++;
    }

    return feedback.str();
}

std::string Compiler::Compiler::CompileLine(std::string &line) {
    std::list<std::string> params = SplitParams(line);
    std::string command = params.front();
    Statements::Statement *statement;
    params.pop_front();

    try {
        statement = Factory::StatementFactory::GetInstance().CreateStatement(command, params);
        if (statement == nullptr)
            return "UNKNOWN INSTRUCTION";
    }
    catch (std::string &error) {
        return error;
    }

    m_program.push_back(statement);
    return "";
}

std::list<std::string> Compiler::Compiler::SplitLines(std::string &code) {
    std::regex lineFilter(".+[^\r\n]");
    std::sregex_iterator it(code.begin(), code.end(), lineFilter);
    std::list<std::string> lines;

    for (; it != std::sregex_iterator(); ++it) {
        lines.push_back((*it).str());
    }

    return lines;
}

std::list<std::string> Compiler::Compiler::SplitParams(std::string &line) {
    std::regex paramFilter("\\S+");
    std::sregex_iterator it(line.begin(), line.end(), paramFilter);
    std::list<std::string> params;

    for (; it != std::sregex_iterator(); ++it) {
        params.push_back((*it).str());
    }

    return params;
}
