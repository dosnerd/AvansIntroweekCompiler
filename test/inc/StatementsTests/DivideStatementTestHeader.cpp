//
// Created by david on 21-2-19.
//

#include "gtest/gtest.h"
#include "Statements/DivideStatement.h"

class DivideStatementTest : public ::testing::Test {

public:
    DivideStatementTest() : memory(nullptr) {}

protected:
    Compiler::Memory *memory;


protected:
    void SetUp() override {
        memory = new Compiler::Memory();
        memory->SetStack(5);
        memory->SetHeap("_five", 5);
    }
};
