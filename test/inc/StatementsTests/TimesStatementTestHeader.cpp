//
// Created by david on 21-2-19.
//

#include "gtest/gtest.h"
#include "Statements/TimesStatement.h"

class TimesStatementTest : public ::testing::Test {

public:
    TimesStatementTest() : memory(nullptr) {}

protected:
    Compiler::Memory *memory;


protected:
    void SetUp() override {
        memory = new Compiler::Memory();
        memory->SetStack(5);
        memory->SetHeap("_five", 5);
    }
};
