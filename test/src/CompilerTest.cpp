//
// Created by david on 21-2-19.
//

#include "../inc/CompilerTestHeader.cpp"

TEST(CompilerTesting, no_code) {
    Compiler::Compiler compiler;
    Compiler::Memory &memory = Compiler::Memory::GetInstance();

    memory.Reset();
    std::string feedback = compiler.Compile("");
    EXPECT_TRUE(feedback.empty());

    unsigned long errorLine = compiler.Run();
    ASSERT_EQ(errorLine, RUN_SUCCEED);
}

TEST(CompilerTesting, one_line_compile) {
    Compiler::Compiler compiler;
    Compiler::Memory &memory = Compiler::Memory::GetInstance();

    memory.Reset();
    std::string feedback = compiler.Compile("SET _TEST 1");

    EXPECT_TRUE(feedback.empty());
}

TEST(CompilerTesting, one_line_run) {
    Compiler::Compiler compiler;
    Compiler::Memory &memory = Compiler::Memory::GetInstance();

    memory.Reset();
    std::string feedback = compiler.Compile("SET _TEST 1");
    ASSERT_TRUE(feedback.empty());

    int errorLine = compiler.Run();

    ASSERT_EQ(errorLine, RUN_SUCCEED);
    EXPECT_EQ(memory.GetHeap("_TEST"), 1);
}

TEST(CompilerTesting, one_line_compile_error) {
    Compiler::Compiler compiler;
    Compiler::Memory &memory = Compiler::Memory::GetInstance();

    memory.Reset();
    std::string feedback = compiler.Compile("GET WRONG AMOUNT OF PARAMS");

    ASSERT_FALSE(feedback.empty());
    std::cout << feedback << std::endl;
}

TEST(CompilerTesting, one_line_runtime_error) {
    Compiler::Compiler compiler;
    Compiler::Memory &memory = Compiler::Memory::GetInstance();
    std::string code = "SET BLA 5";

    memory.Reset();
    std::string feedback = compiler.Compile(code);
    ASSERT_TRUE(feedback.empty());

    unsigned long errorLine = compiler.Run();
    EXPECT_EQ(errorLine, 1);
    std::cout << feedback << std::endl;
    std::cout << compiler.RunTimeErrorReport(code) << std::endl;
}

TEST(CompilerTesting, multi_line_compile) {
    Compiler::Compiler compiler;
    Compiler::Memory &memory = Compiler::Memory::GetInstance();

    memory.Reset();
    std::string feedback = compiler.Compile(
            "SET _TEST 1\r\n"
            "GET _TEST\r\n"
            "\r\n"
            "ADD 5\r\n"
            "SET _END");

    EXPECT_TRUE(feedback.empty());
}

TEST(CompilerTesting, multi_line_compile_without_cariage_return) {
    Compiler::Compiler compiler;
    Compiler::Memory &memory = Compiler::Memory::GetInstance();

    memory.Reset();
    std::string feedback = compiler.Compile(
            "SET _TEST 1\n"
            "GET _TEST\n"
            "\r\n"
            "ADD 5\n"
            "SET _END");

    EXPECT_TRUE(feedback.empty());
}

TEST(CompilerTesting, multi_line_run) {
    Compiler::Compiler compiler;
    Compiler::Memory &memory = Compiler::Memory::GetInstance();

    memory.Reset();
    std::string feedback = compiler.Compile(
            "SET _TEST 1\r\n"
            "GET _TEST\r\n"
            "\r\n"
            "ADD 5\r\n"
            "SET _END"
    );
    ASSERT_TRUE(feedback.empty());

    unsigned long errorLine = compiler.Run();
    ASSERT_EQ(errorLine, RUN_SUCCEED);
    EXPECT_EQ(memory.GetHeap("_TEST"), 1);
}

TEST(CompilerTesting, multi_line_compile_error) {
    Compiler::Compiler compiler;
    Compiler::Memory &memory = Compiler::Memory::GetInstance();

    memory.Reset();
    std::string feedback = compiler.Compile(
            "SET WRONG AMOUNT OF PARAMS\r\n"
            "GET _TEST\r\n"
            "\r\n"
            "ADD five\r\n"
            "SET _END"
    );

    ASSERT_FALSE(feedback.empty());
    std::cout << feedback << std::endl;
}

TEST(CompilerTesting, multi_line_runtime_error) {
    Compiler::Compiler compiler;
    Compiler::Memory &memory = Compiler::Memory::GetInstance();
    std::string code =
            "SET _TEST 1\r\n"
            "GET TEST\r\n"
            "\r\n"
            "ADD 5\r\n"
            "SET _END";

    memory.Reset();
    std::string feedback = compiler.Compile(code);
    ASSERT_TRUE(feedback.empty());

    unsigned long errorLine = compiler.Run();
    EXPECT_EQ(errorLine, 2);

    std::cout << feedback << std::endl;
    std::cout << compiler.RunTimeErrorReport(code) << std::endl;
}