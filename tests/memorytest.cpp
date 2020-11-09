
#include "memorytest.h"
#include "memoryleaks.h"

MemoryTest::MemoryTest() :  ::testing::Test(),
                            _preExistingLeaks(){
}

MemoryTest::~MemoryTest() {
}

void MemoryTest::SetUp() {
    ::testing::Test::SetUp();

    _preExistingLeaks = MemoryLeaks::measureLeaks();
}

void MemoryTest::TearDown() {
    ASSERT_FALSE((MemoryLeaks::measureLeaks() - _preExistingLeaks).hasBeenLeaks()) << "Leaks were found!";

    ::testing::Test::TearDown();
}