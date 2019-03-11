//
// Created by david on 21-2-19.
//

#include "../../inc/StatementsTests/GetStatementTestHeader.cpp"

TEST_F(GetStatementTest, Input) {
    Compiler::Statements::Statement *get = new Compiler::Statements::GetStatement("INPUT_A");
    get->SetMemory(memory);

    EXPECT_TRUE(get->Execute());
    ASSERT_EQ(memory->GetStack(), 1);
}

TEST_F(GetStatementTest, Params_correct) {
    std::list<std::string> params;
    Compiler::Statements::Statement *get;

    params.emplace_back("INPUT_A");
    get = new Compiler::Statements::GetStatement(params, 1);
    get->SetMemory(memory);

    EXPECT_TRUE(get->Execute());
    ASSERT_EQ(memory->GetStack(), 1);
}

TEST_F(GetStatementTest, Params_incorrect) {
    std::list<std::string> params;
    Compiler::Statements::Statement *get;

    try {
        get = new Compiler::Statements::GetStatement(params, 1);
        FAIL();
    } catch (std::string &error) {
        ASSERT_EQ(error, INVALID_COUNT_PARAMS);
    }
}

TEST_F(GetStatementTest, Output) {
    Compiler::Statements::Statement *get = new Compiler::Statements::GetStatement("OUTPUT_1");
    get->SetMemory(memory);

    EXPECT_TRUE(get->Execute());
    ASSERT_EQ(memory->GetStack(), 2);
}

TEST_F(GetStatementTest, Custom) {
    Compiler::Statements::Statement *get = new Compiler::Statements::GetStatement("_TEST");
    get->SetMemory(memory);

    EXPECT_TRUE(get->Execute());
    ASSERT_EQ(memory->GetStack(), 3);
}