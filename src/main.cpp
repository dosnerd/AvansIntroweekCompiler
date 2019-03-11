//
// Created by david on 9-3-19.
//

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Compiler.h>

int RunFile(const std::string &code);

std::string LoadFromFile(const std::string &filename){
    std::ifstream file(filename);

    if (file.good()){
        std::ostringstream contents;
        contents << file.rdbuf();
        file.close();
        return(contents.str());
    } else {
        std::cerr << "Failed to load file '" << filename << std::endl;
    }

    return "";
}

void DumpMemory(){
    Compiler::Memory &memory = Compiler::Memory::GetInstance();
    const std::map<std::string, int> heap = memory.GetHeap();
    auto it = heap.begin();

    std::cout << "=====MEMORY DUMP=====" << std::endl;
    std::cout << "STACK: " << memory.GetStack() << std::endl;
    std::cout << "DYNAMIC: " << std::endl;
    for (; it != heap.end(); ++it){
        std::cout << "\t[" << it->first << "]: " << it->second << std::endl;
    }
    std::cout << "======END DUMP=======" << std::endl;
}

int main(int argc, char *argv[]) {
    std::string code;
    bool dumpMemory = false;

    for (int i = 1; i < argc; ++i){
        std::string param(argv[i]);
        if (param == "-m"){
            dumpMemory = true;
        } else {
            code += LoadFromFile(param) + "\n";
        }
    }

    int rVal = RunFile(code);
    if (dumpMemory) DumpMemory();

    return rVal;
}

int RunFile(const std::string &code) {
    Compiler::Compiler compiler;
    std::string feedback = compiler.Compile(code);
    if (!feedback.empty()){
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