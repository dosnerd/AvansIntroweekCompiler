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
    unsigned programPointer = 0;
    m_errorLine = 1;

    while (programPointer < m_program.size()){
        try {
            Statements::Statement *statement = m_program[programPointer++];
            Memory::GetInstance().SetHeap("PROGRAM_POINTER", programPointer);

            if (statement == nullptr) continue;

            if (!statement->Execute()) {
                m_error = "FAILED TO EXECUTE";
                return m_errorLine;
            }

            programPointer = static_cast<unsigned int>(Memory::GetInstance().GetHeap("PROGRAM_POINTER"));
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
    std::string command;
    Statements::Statement *statement;

    if (params.size() == 0){
        m_program.push_back(nullptr);
        return "";
    }

    command = params.front();
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
    std::regex lineFilter(".*\r?(\n|$)");
    std::sregex_iterator it(code.begin(), code.end(), lineFilter);
    std::list<std::string> lines;

    for (; it != std::sregex_iterator(); ++it) {
        std::string line = it->str();
        line = Replace(line, "\r", "");
        line = Replace(line, "\n", " ");
        lines.push_back(line);
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

std::string Compiler::Compiler::Replace(std::string str, std::string search, std::string replace) {
    size_t start_pos = str.find(search);
    if(start_pos == std::string::npos)
        return str;
    str.replace(start_pos, search.length(), replace);
    return str;
}
