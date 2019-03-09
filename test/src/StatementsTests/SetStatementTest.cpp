//
// Created by david on 21-2-19.
//

#include "../../inc/StatementsTests/SetStatementTestHeader.cpp"

TEST_F(SetStatementTest, StackToInput) {
    Compiler::Statements::Statement *set = new Compiler::Statements::SetStatement("INPUT_A");
    set->SetMemory(memory);

    ASSERT_TRUE(set->Execute());
    ASSERT_EQ(memory->GetHeap("INPUT_A"), 5);
}

TEST_F(SetStatementTest, StackToOutput) {
    Compiler::Statements::Statement *set = new Compiler::Statements::SetStatement("OUTPUT_1");
    set->SetMemory(memory);

    ASSERT_TRUE(set->Execute());
    ASSERT_EQ(memory->GetHeap("OUTPUT_1"), 5);
}

TEST_F(SetStatementTest, StackToCustom) {
    Compiler::Statements::Statement *set = new Compiler::Statements::SetStatement("_TEST");
    set->SetMemory(memory);

    ASSERT_TRUE(set->Execute());
    ASSERT_EQ(memory->GetHeap("_TEST"), 5);
}

TEST_F(SetStatementTest, ValueToInput) {
    Compiler::Statements::Statement *set = new Compiler::Statements::SetStatement(7, "INPUT_A");
    set->SetMemory(memory);

    ASSERT_TRUE(set->Execute());
    ASSERT_EQ(memory->GetHeap("INPUT_A"), 7);
}

TEST_F(SetStatementTest, ValueToOutput) {
    Compiler::Statements::Statement *set = new Compiler::Statements::SetStatement(8, "OUTPUT_1");
    set->SetMemory(memory);

    ASSERT_TRUE(set->Execute());
    ASSERT_EQ(memory->GetHeap("OUTPUT_1"), 8);

}

TEST_F(SetStatementTest, ValueToCustom) {
    Compiler::Statements::Statement *set = new Compiler::Statements::SetStatement(9, "_TEST");
    set->SetMemory(memory);

    ASSERT_TRUE(set->Execute());
    ASSERT_EQ(memory->GetHeap("_TEST"), 9);
}

TEST_F(SetStatementTest, Params_correct_1) {
    std::list<std::string> params;
    Compiler::Statements::Statement *set;

    params.emplace_back("OUTPUT_1");
    set = new Compiler::Statements::SetStatement(params);
    set->SetMemory(memory);

    EXPECT_TRUE(set->Execute());
    ASSERT_EQ(memory->GetHeap("OUTPUT_1"), memory->GetStack());
}

TEST_F(SetStatementTest, Params_correct_2) {
    std::list<std::string> params;
    Compiler::Statements::Statement *set;

    params.emplace_back("_TEST");
    params.emplace_back("224");
    set = new Compiler::Statements::SetStatement(params);
    set->SetMemory(memory);

    EXPECT_TRUE(set->Execute());
    ASSERT_EQ(memory->GetHeap("_TEST"), 224);
}

TEST_F(SetStatementTest, Params_correct_2_value_0) {
    std::list<std::string> params;
    Compiler::Statements::Statement *set;

    params.emplace_back("_TEST");
    params.emplace_back("0");
    set = new Compiler::Statements::SetStatement(params);
    set->SetMemory(memory);

    EXPECT_TRUE(set->Execute());
    ASSERT_EQ(memory->GetHeap("_TEST"), 0);
}

TEST_F(SetStatementTest, Params_incorrect_amount) {
    std::list<std::string> params;
    Compiler::Statements::Statement *set;

    try {
        set = new Compiler::Statements::SetStatement(params);
        FAIL();
    } catch (std::string &error) {
        ASSERT_EQ(error, INVALID_COUNT_PARAMS);
    }
}

TEST_F(SetStatementTest, Params_incorrect_format) {
    std::list<std::string> params;
    Compiler::Statements::Statement *set;

    params.emplace_back("_TEST");
    params.emplace_back("not_number");

    try {
        set = new Compiler::Statements::SetStatement(params);
        FAIL();
    } catch (std::string &error) {
        ASSERT_EQ(error, INVALID_PARAM(2));
    }
}