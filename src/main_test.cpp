#include <iostream>

#ifdef TESTING

#include <gtest/gtest.h>

#endif


int main(int argc, char **argv) {
#ifdef TESTING
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#else
    return 0;
#endif
}