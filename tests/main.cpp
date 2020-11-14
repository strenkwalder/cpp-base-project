#include <gtest/gtest.h>

#include "dummyTest.h"
#include "memoryleaksTest.h"

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
