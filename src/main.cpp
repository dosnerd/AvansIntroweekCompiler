//
// Created by david on 9-3-19.
//

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Compiler.h>

int RunFile(const std::string &code);

int RunStream(const std::string &code);

std::string LoadFromFile(const std::string &filename) {
    std::ifstream file(filename);

    if (file.good()) {
        std::ostringstream contents;
        contents << file.rdbuf();
        file.close();
        return (contents.str());
    } else {
        std::cerr << "Failed to load file '" << filename << "'" << std::endl;
    }

    return "";
}

void DumpMemory() {
    Compiler::Memory &memory = Compiler::Memory::GetInstance();
    const std::map<std::string, int> heap = memory.GetHeap();
    auto it = heap.begin();

    std::cout << "=====MEMORY DUMP=====" << std::endl;
    std::cout << "STACK: " << memory.GetStack() << std::endl;
    std::cout << "DYNAMIC: " << std::endl;
    for (; it != heap.end(); ++it) {
        std::cout << "\t[" << it->first << "]: " << it->second << std::endl;
    }
    std::cout << "======END DUMP=======" << std::endl;
}

int main(int argc, char *argv[]) {
    std::string code;
    bool dumpMemory = false;
    bool stream = false;
    int rVal;

    for (int i = 1; i < argc; ++i) {
        std::string param(argv[i]);
        if (param == "-m") {
            dumpMemory = true;
        } else if (param == "-s") {
            stream = true;
        } else {
            code += LoadFromFile(param) + "\n";
        }
    }


    if (stream) {
        rVal = RunStream(code);
    } else {
        rVal = RunFile(code);
    }
    if (dumpMemory) DumpMemory();

    return rVal;
}

int RunFile(const std::string &code) {
    Compiler::Compiler compiler;
    std::string feedback = compiler.Compile(code);
    if (!feedback.empty()) {
        std::cout << feedback << std::endl;
        return 1;
    }

    if (compiler.Run() != RUN_SUCCEED) {
        feedback = compiler.RunTimeErrorReport(code);
        if (!feedback.empty()) {
            std::cout << feedback << std::endl;
            return 1;
        }
    };

    return 0;
}

void DumpStream() {
    try {
        Compiler::Memory &memory = Compiler::Memory::GetInstance();
        for (int i = 1; i<50; ++i){
            std::cout << memory.GetHeap("OUTPUT_" + std::to_string(i)) << std::endl;
        }
    } catch (std::string &err){
    }
    std::cout << "END" << std::endl;
}

int RunStream(const std::string &code) {
    Compiler::Compiler compiler;
    std::string line;
    std::string feedback = compiler.Compile(code);
    Compiler::Memory &memory = Compiler::Memory::GetInstance();
    char input;

    if (!feedback.empty()) {
        std::cout << "ERROR" << std::endl;
        std::cout << feedback << std::endl;

        std::cin >> line;   //Wait for close
        return 1;
    }

    do {
        std::cin >> line;
        input = 'A';

        while (line != "-") {
            memory.SetHeap(std::string("INPUT_") + input, std::stoi(line));

            input++;
            std::cin >> line;
        }

        if (compiler.Run() != RUN_SUCCEED) {
            std::cout << "ERROR" << std::endl;

            feedback = compiler.RunTimeErrorReport(code);
            if (!feedback.empty()) {
                std::cout << feedback << std::endl;
                return 1;
            }
        } else {
            std::cout << "DONE" << std::endl;
        }


        DumpStream();
        std::cin >> line;
    } while (line == "NEXT");

    return 0;
}