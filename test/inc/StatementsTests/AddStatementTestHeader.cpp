//
// Created by david on 21-2-19.
//

#include "gtest/gtest.h"
#include "../../../inc/Statements/AddStatement.h"

class AddStatementTest : public ::testing::Test {

public:
    AddStatementTest() : memory(nullptr) {}

protected:
    Compiler::Memory *memory;


protected:
    void SetUp() override {
        memory = new Compiler::Memory();
        memory->SetStack(5);
        memory->SetHeap("_five", 5);
    }
};
