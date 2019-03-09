//
// Created by david on 21-2-19.
//

#include "../inc/MemoryTestHeader.cpp"

TEST_F(MemoryData, read_stack) {
    ASSERT_EQ(memory->GetStack(), 0);
}

TEST_F(MemoryData, write_stack) {
    memory->SetStack(5);
    ASSERT_EQ(memory->GetStack(), 5);
}

TEST_P(HeapTesting, read_heap) {
    HeapData data = GetParam();
    int value = 0;

    try {
        value = memory->GetHeap(data.name);
        ASSERT_EQ(value, data.oldValue);

        if (!data.readSucceed)
            FAIL();
    } catch (std::string &error){
        ASSERT_FALSE(data.readSucceed);
    }
}

TEST_P(HeapTesting, write_heap) {
    HeapData data = GetParam();
    bool succeed;
    int value;

    try {
        succeed = memory->SetHeap(data.name, data.newValue);
        value = memory->GetHeap(data.name);

        ASSERT_EQ(succeed, data.writeSucceed);
        if (succeed) {
            ASSERT_EQ(value, data.newValue);
        } else {
            ASSERT_EQ(value, data.oldValue);
        }
    }
    catch (std::string &error){
        ASSERT_FALSE(data.writeSucceed);
    }
}

INSTANTIATE_TEST_CASE_P

(CorrectPorts, HeapTesting,
 ::testing::Values(
         HeapData{"INPUT_A",  1, 5 , true, true},
         HeapData{"INPUT_B",  2, 10, true, true},
         HeapData{"OUTPUT_1", 0, 6 , true, true},
         HeapData{"OUTPUT_2", 0, 98, true, true}
 ));

INSTANTIATE_TEST_CASE_P

(IncorrectPort, HeapTesting,
 ::testing::Values(
         HeapData{"INPUT_Q",    0, 15, true, false},
         HeapData{"INPUT_1",    0, 24, true, false},
         HeapData{"OUTPUT_100", 0, 74, true, false},
         HeapData{"OUTPUT_A",   0, 12, true, false}
 ));

INSTANTIATE_TEST_CASE_P

(CorrectCustoms, HeapTesting,
::testing::Values(
        HeapData{"_T1", 0, 48, true, true},
        HeapData{"_T2", 0, 54, true, true}
));

INSTANTIATE_TEST_CASE_P

(NotExisting, HeapTesting,
 ::testing::Values(
         HeapData{"_Bla",        0, 32, true, false},
         HeapData{"OUTPUT_ABC",  0, 32, true, false},
         HeapData{"INPUT_123",   0, 32, true, false}
 ));

INSTANTIATE_TEST_CASE_P

(IncorrectCustoms, HeapTesting,
 ::testing::Values(
         HeapData{"BLA",    0, 32, false, false},
         HeapData{"INPUT_",  0, 14, false, false},
         HeapData{"INPUT",  0, 14, false, false},
         HeapData{"OUTPUT_", 0, 97, false, false},
         HeapData{"OUTPUT", 0, 97, false, false}
 ));