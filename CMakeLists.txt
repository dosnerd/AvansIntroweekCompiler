cmake_minimum_required(VERSION 3.13)
project(compiler)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin/)


# Define our host system
SET(CMAKE_SYSTEM_NAME Linux)

# Define the cross compiler locations
SET(CMAKE_C_COMPILER   /media/david/DATA_2/school/3.3/Project/codes/tools/arm-bcm2708/arm-rpi-4.9.3-linux-gnueabihf/bin/arm-linux-gnueabihf-g++)
SET(CMAKE_CXX_COMPILER /media/david/DATA_2/school/3.3/Project/codes/tools/arm-bcm2708/arm-rpi-4.9.3-linux-gnueabihf/bin/arm-linux-gnueabihf-g++)

# Define the sysroot path for the RaspberryPi distribution in our tools folder
SET(CMAKE_FIND_ROOT_PATH /media/david/DATA_2/school/3.3/Project/codes/tools/arm-bcm2708/arm-rpi-4.9.3-linux-gnueabihf/arm-linux-gnueabihf/sysroot/)

# Use our definitions for compiler tools
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# Search for libraries and headers in the target directories only
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

include_directories(inc)

add_executable(run src/Statements/Statement.cpp inc/Statements/Statement.h src/Memory.cpp inc/Memory.h src/Statements/GetStatement.cpp inc/Statements/GetStatement.h src/Statements/SetStatement.cpp inc/Statements/SetStatement.h src/Statements/AddStatement.cpp inc/Statements/AddStatement.h src/Factory/StatementFactory.cpp inc/Factory/StatementFactory.h inc/Factory/StatementCreator.h inc/Factory/StatementCreatorInstance.h src/main.cpp src/Compiler.cpp inc/Compiler.h src/Statements/TimesStatement.cpp inc/Statements/TimesStatement.h src/Statements/DivideStatement.cpp inc/Statements/DivideStatement.h)

add_definitions(-Wall)