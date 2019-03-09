//
// Created by david on 21-2-19.
//

#include "gtest/gtest.h"
#include "../../../inc/Statements/GetStatement.h"

class GetStatementTest : public ::testing::Test {

public:
    GetStatementTest() : memory(nullptr) {}

protected:
    Compiler::Memory *memory;


protected:
    void SetUp() override {
        memory = new Compiler::Memory();
        memory->SetHeap("INPUT_A", 1);
        memory->SetHeap("OUTPUT_1", 2);
        memory->SetHeap("_TEST", 3);
    }
};
