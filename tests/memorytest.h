#ifndef MEMORYTEST_H
#define MEMORYTEST_H

#include "memoryleaks.h"
#include <gtest/gtest.h>

class MemoryTest : public ::testing::Test {
protected:
private:
    MemoryLeaks _preExistingLeaks;

public:
    MemoryTest();
    ~MemoryTest() override;

    void SetUp() override;
    void TearDown() override;

};

#endif // MEMORYTEST_H
