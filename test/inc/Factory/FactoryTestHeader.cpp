//
// Created by david on 9-3-19.
//


#include <Factory/StatementCreatorInstance.h>
#include <Statements/GetStatement.h>
#include <Statements/SetStatement.h>
#include "gtest/gtest.h"
#include "Factory/StatementFactory.h"

class FactoryTest : public ::testing::Test {
public:
    FactoryTest() : factory(nullptr), setCreator(nullptr), getCreator(nullptr) {};

protected:
    void SetUp() override {
        factory = new Compiler::Factory::StatementFactory();

        getCreator = new Compiler::Factory::StatementCreatorInstance
                <Compiler::Statements::GetStatement>("TEST_GET");
        setCreator = new Compiler::Factory::StatementCreatorInstance
                <Compiler::Statements::SetStatement>("TEST_SET");

        factory->AddCreator("TEST_GET", getCreator);
        factory->AddCreator("TEST_SET", setCreator);

        memory = new Compiler::Memory();
        memory->SetHeap("INPUT_A", 5);
        memory->SetStack(12);
    }

    void TearDown() override {
        delete factory;
        delete getCreator;
        delete setCreator;
        delete memory;
    }

protected:
    Compiler::Memory *memory;
    Compiler::Factory::StatementFactory *factory;
    Compiler::Factory::StatementCreatorInstance<Compiler::Statements::GetStatement> *getCreator;
    Compiler::Factory::StatementCreatorInstance<Compiler::Statements::SetStatement> *setCreator;
};