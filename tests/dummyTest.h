#ifndef DUMMYTEST_H
#define DUMMYTEST_H

#include "memorytest.h"

#include "../src/dummy.h"

class DummyTest : public MemoryTest {};

TEST_F(DummyTest, a_new_object_has_no_data)
{
  Dummy d;
  ASSERT_FALSE(d.hasData()) << "A new object should not have any data.";
  ASSERT_EQ(d.data(), nullptr) << "A new object should only have a nullpointer";
}

TEST_F(DummyTest, setting_data_should_be_recognised)
{
    Dummy d;
    d.data() = new int[4];

    ASSERT_TRUE(d.hasData()) << "A Dummy should not have any data if it was set.";

    delete[] d.data();
}
#endif // DUMMYTEST_H
