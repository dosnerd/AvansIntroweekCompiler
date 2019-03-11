//
// Created by david on 9-3-19.
//

#include "../../inc/Factory/FactoryTestHeader.cpp"

TEST_F(FactoryTest, create){
    std::list<std::string> params;

    params.emplace_back("INPUT_A");
    Compiler::Statements::Statement *statement = factory->CreateStatement("TEST_GET", params, 1);

    ASSERT_NE(statement, nullptr);
}

TEST_F(FactoryTest, create_params_GET){
    std::list<std::string> params;
    Compiler::Statements::Statement *statement;

    params.emplace_back("INPUT_A");
    statement = factory->CreateStatement("TEST_GET", params, 1);

    ASSERT_NE(statement, nullptr);

    statement->SetMemory(memory);
    ASSERT_TRUE(statement->Execute());

    ASSERT_EQ(memory->GetStack(), 5);
}

TEST_F(FactoryTest, create_params_SET){
    std::list<std::string> params;
    Compiler::Statements::Statement *statement;

    params.emplace_back("OUTPUT_1");
    statement = factory->CreateStatement("TEST_SET", params, 1);

    ASSERT_NE(statement, nullptr);

    statement->SetMemory(memory);
    ASSERT_TRUE(statement->Execute());

    ASSERT_EQ(memory->GetHeap("OUTPUT_1"), 12);
}

TEST_F(FactoryTest, not_found){
    std::list<std::string> params;
    Compiler::Statements::Statement *statement = factory->CreateStatement("TEST_NOT_EXISTS", params, 1);

    ASSERT_EQ(statement, nullptr);
}