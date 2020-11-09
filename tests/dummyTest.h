#ifndef DUMMYTEST_H
#define DUMMYTEST_H

#include "memorytest.h"

#include "../src/dummy.h"

TEST_F(MemoryTest, CreationTest)
{
  Dummy d;
  //ASSERT_EQ(d.data(), nullptr) << "Data pointer has not been initialised correctly " << d.data();
}

#endif // DUMMYTEST_H
