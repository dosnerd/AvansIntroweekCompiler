cmake_minimum_required(VERSION 3.13)
project(compiler)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(google_test)
include_directories(google_test/googletest/include google_test/googletest)
include_directories(inc)

add_definitions(-DTESTING)

add_executable(runCompilerTests src/main_test.cpp test/src/MemoryTest.cpp src/Statements/Statement.cpp inc/Statements/Statement.h src/Memory.cpp inc/Memory.h test/inc/MemoryTestHeader.cpp src/Statements/GetStatement.cpp inc/Statements/GetStatement.h test/inc/StatementsTests/GetStatementTestHeader.cpp test/src/StatementsTests/GetStatementTest.cpp src/Statements/SetStatement.cpp inc/Statements/SetStatement.h test/inc/StatementsTests/SetStatementTestHeader.cpp test/src/StatementsTests/SetStatementTest.cpp src/Statements/AddStatement.cpp inc/Statements/AddStatement.h test/inc/StatementsTests/AddStatementTestHeader.cpp test/src/StatementsTests/AddStatementTest.cpp src/Factory/StatementFactory.cpp inc/Factory/StatementFactory.h inc/Factory/StatementCreator.h inc/Factory/StatementCreatorInstance.h test/src/Factory/FactoryTest.cpp src/Compiler.cpp inc/Compiler.h test/src/CompilerTest.cpp test/inc/CompilerTestHeader.cpp test/src/StatementsTests/TimesStatementTest.cpp test/inc/StatementsTests/TimesStatementTestHeader.cpp  src/Statements/TimesStatement.cpp inc/Statements/TimesStatement.h src/Statements/DivideStatement.cpp inc/Statements/DivideStatement.h test/inc/StatementsTests/DivideStatementTestHeader.cpp test/src/StatementsTests/DivideStatementTest.cpp)
add_executable(run src/Statements/Statement.cpp inc/Statements/Statement.h src/Memory.cpp inc/Memory.h src/Statements/GetStatement.cpp inc/Statements/GetStatement.h src/Statements/SetStatement.cpp inc/Statements/SetStatement.h src/Statements/AddStatement.cpp inc/Statements/AddStatement.h src/Factory/StatementFactory.cpp inc/Factory/StatementFactory.h inc/Factory/StatementCreator.h inc/Factory/StatementCreatorInstance.h src/main.cpp src/Compiler.cpp inc/Compiler.h src/Statements/TimesStatement.cpp inc/Statements/TimesStatement.h src/Statements/DivideStatement.cpp inc/Statements/DivideStatement.h)

target_link_libraries(runCompilerTests gtest gtest_main)