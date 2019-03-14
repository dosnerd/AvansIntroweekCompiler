//
// Created by david on 21-2-19.
//

#include "../../inc/StatementsTests/DivideStatementTestHeader.cpp"

TEST_F(DivideStatementTest, PositiveNumber) {
    std::list<std::string> params;
    Compiler::Statements::Statement *times;

    params.emplace_back("2");

    times = new Compiler::Statements::DivideStatement(params, 1);
    times->SetMemory(memory);

    EXPECT_TRUE(times->Execute());
    ASSERT_EQ(memory->GetStack(), 5 / 2);
}

TEST_F(DivideStatementTest, NegativeNumber) {
    std::list<std::string> params;
    Compiler::Statements::Statement *times;

    params.emplace_back("-2");

    times = new Compiler::Statements::DivideStatement(params, 1);
    times->SetMemory(memory);

    EXPECT_TRUE(times->Execute());
    ASSERT_EQ(memory->GetStack(), 5 / -2);
}

TEST_F(DivideStatementTest, Params_incorrect) {
    std::list<std::string> params;
    Compiler::Statements::Statement *times;

    try {
        times = new Compiler::Statements::DivideStatement(params, 1);
        FAIL();
    } catch (std::string &error) {
        ASSERT_EQ(error, INVALID_COUNT_PARAMS);
    }
}

TEST_F(DivideStatementTest, Params_add_variable) {
    std::list<std::string> params;
    Compiler::Statements::Statement *times;

    params.emplace_back("_five");

    times = new Compiler::Statements::DivideStatement(params, 1);
    times->SetMemory(memory);
    ASSERT_TRUE(times->Execute());
    ASSERT_EQ(memory->GetStack(), 5 / 5);
}

TEST_F(DivideStatementTest, Params_incorrect_format_invalid_name) {
    std::list<std::string> params;
    Compiler::Statements::Statement *times;

    params.emplace_back("not_number");

    try {
        times = new Compiler::Statements::DivideStatement(params, 1);
        times->Execute();
        FAIL();
    } catch (std::string &error) {
        ASSERT_EQ(error, INVALID_NAME);
    }
}

TEST_F(DivideStatementTest, Params_incorrect_format_param_not_exists) {
    std::list<std::string> params;
    Compiler::Statements::Statement *times;

    params.emplace_back("_not_exists");

    try {
        times = new Compiler::Statements::DivideStatement(params, 1);
        times->Execute();
        FAIL();
    } catch (std::string &error) {
        ASSERT_EQ(error, VAR_NOT_FOUND);
    }
}

TEST_F(DivideStatementTest, Divide_by_zero) {
    std::list<std::string> params;
    Compiler::Statements::Statement *times;

    params.emplace_back("0");

    try {
        times = new Compiler::Statements::DivideStatement(params, 1);
        times->Execute();
        FAIL();
    } catch (std::string &error) {
        ASSERT_EQ(error, DIVIDE_BY_ZERO);
    }
}