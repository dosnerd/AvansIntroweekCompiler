//
// Created by david on 21-2-19.
//

#ifndef COMPILER_MEMORYTEST_H
#define COMPILER_MEMORYTEST_H

#include "gtest/gtest.h"
#include "../../inc/Memory.h"

class MemoryData : public ::testing::Test {
public:
    MemoryData() : memory(nullptr) {};

protected:
    void SetUp() override {
        memory = new Compiler::Memory();

        memory->SetHeap("INPUT_A", 1);
        memory->SetHeap("INPUT_B", 2);
        memory->SetHeap("INPUT_C", 4);
        memory->SetHeap("INPUT_D", -5);

        memory->SetHeap("OUTPUT_1", 0);
        memory->SetHeap("OUTPUT_2", 0);
        memory->SetHeap("OUTPUT_3", 0);
        memory->SetHeap("OUTPUT_4", 0);

        memory->SetHeap("_T1", 0);
        memory->SetHeap("_T2", 0);
    }


    void TearDown() override {
        delete memory;
    }


protected:
    Compiler::Memory *memory;
};


struct HeapData {
    std::string name;

    int oldValue;
    int newValue;
    bool writeSucceed;
    bool readSucceed;
};

class HeapTesting : public MemoryData, public ::testing::WithParamInterface<HeapData> {

};

#endif //COMPILER_MEMORYTEST_H
