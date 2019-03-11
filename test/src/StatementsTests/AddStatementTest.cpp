//
// Created by david on 21-2-19.
//

#include "../../inc/StatementsTests/AddStatementTestHeader.cpp"

TEST_F(AddStatementTest, PositiveNumber){
    Compiler::Statements::Statement *add = new Compiler::Statements::AddStatement(12);
    add->SetMemory(memory);

    EXPECT_TRUE(add->Execute());
    ASSERT_EQ(memory->GetStack(), 5 + 12);
}

TEST_F(AddStatementTest, NegativeNumber){
    Compiler::Statements::Statement *add = new Compiler::Statements::AddStatement(-14);
    add->SetMemory(memory);

    EXPECT_TRUE(add->Execute());
    ASSERT_EQ(memory->GetStack(), 5 + -14);
}


TEST_F(AddStatementTest, Params_correct) {
    std::list<std::string> params;
    Compiler::Statements::Statement *add;

    params.emplace_back("58");
    add = new Compiler::Statements::AddStatement(params, 1);
    add->SetMemory(memory);

    EXPECT_TRUE(add->Execute());
    ASSERT_EQ(memory->GetStack(), 5 + 58);
}

TEST_F(AddStatementTest, Params_correct_negative) {
    std::list<std::string> params;
    Compiler::Statements::Statement *add;

    params.emplace_back("-58");
    add = new Compiler::Statements::AddStatement(params, 1);
    add->SetMemory(memory);

    EXPECT_TRUE(add->Execute());
    ASSERT_EQ(memory->GetStack(), 5 - 58);
}

TEST_F(AddStatementTest, Params_incorrect) {
    std::list<std::string> params;
    Compiler::Statements::Statement *add;

    try {
        add = new Compiler::Statements::AddStatement(params, 1);
        FAIL();
    } catch (std::string &error) {
        ASSERT_EQ(error, INVALID_COUNT_PARAMS);
    }
}

TEST_F(AddStatementTest, Params_add_variable) {
    std::list<std::string> params;
    Compiler::Statements::Statement *add;

    params.emplace_back("_five");

    add = new Compiler::Statements::AddStatement(params, 1);
    add->SetMemory(memory);
    add->Execute();

    ASSERT_EQ(memory->GetStack(), 10);
}


TEST_F(AddStatementTest, Params_incorrect_format_invalid_name) {
    std::list<std::string> params;
    Compiler::Statements::Statement *add;

    params.emplace_back("not_number");

    try {
        add = new Compiler::Statements::AddStatement(params, 1);
        add->Execute();
        FAIL();
    } catch (std::string &error) {
        ASSERT_EQ(error, INVALID_NAME);
    }
}

TEST_F(AddStatementTest, Params_incorrect_format_param_not_exists) {
    std::list<std::string> params;
    Compiler::Statements::Statement *add;

    params.emplace_back("_not_exists");

    try {
        add = new Compiler::Statements::AddStatement(params, 1);
        add->Execute();
        FAIL();
    } catch (std::string &error) {
        ASSERT_EQ(error, VAR_NOT_FOUND);
    }
}