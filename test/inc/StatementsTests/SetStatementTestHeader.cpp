//
// Created by david on 21-2-19.
//

#include "gtest/gtest.h"
#include "../../../inc/Statements/SetStatement.h"
#include "../../../inc/Memory.h"

class SetStatementTest : public ::testing::Test {

public:
    SetStatementTest() : memory(nullptr) {}

protected:
    Compiler::Memory *memory;


protected:
    void SetUp() override {
        memory = new Compiler::Memory();
        memory->SetStack(5);
    }
};