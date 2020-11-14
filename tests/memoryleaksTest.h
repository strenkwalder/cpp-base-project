#ifndef MEMORYLEAKS_TEST_H
#define MEMORYLEAKS_TEST_H

#include "memorytest.h"
#include "memoryleaks.h"

TEST(MemoryLeaks_Test, empty_object_has_no_leaks)
{
    MemoryLeaks leaks_implicit;
    ASSERT_FALSE(leaks_implicit.hasBeenLeaks()) << "An empty MemoryLeaks object should have no leaks recorded";

    MemoryLeaks leaks_explicit(0,0,0,0);
    ASSERT_FALSE(leaks_explicit.hasBeenLeaks()) << "An empty MemoryLeaks object should have no leaks recorded";
}

TEST(MemoryLeaks_Test, object_with_leaks_had_leaks)
{
    MemoryLeaks leaks_clear(1,0,0,0);
    ASSERT_TRUE(leaks_clear.hasBeenLeaks()) << "An clear leaks should have been recorded";

    MemoryLeaks leaks_dubious(0,1,0,0);
    ASSERT_TRUE(leaks_dubious.hasBeenLeaks()) << "An dubious leaks should have been recorded";

    MemoryLeaks leaks_reachable(0,0,1,0);
    ASSERT_TRUE(leaks_reachable.hasBeenLeaks()) << "An reachable leaks should have been recorded";

    MemoryLeaks leaks_supressed(0,0,0,1);
    ASSERT_TRUE(leaks_dubious.hasBeenLeaks()) << "An supressed leaks should have been recorded";
}

TEST(MemoryLeaks_Test, adding_and_subtracting_leaks_to_empty_object) {
    MemoryLeaks leaks;
    MemoryLeaks extra_leaks(1, 1, 1, 1);

    ASSERT_FALSE((leaks + leaks).hasBeenLeaks()) << "Adding two empty objects should result in no leaks.";
    ASSERT_FALSE((extra_leaks - extra_leaks).hasBeenLeaks()) << "Subtracting the same objects should result in no leaks.";

    leaks += extra_leaks;
    ASSERT_TRUE(leaks.hasBeenLeaks()) << "Adding leaks to an empty MemoryLeaks object should have recorded leaks.";

    leaks -= extra_leaks;
    ASSERT_FALSE(leaks.hasBeenLeaks()) << "Subtracting the leaks should create no leaks.";
}

#endif // MEMORYLEAKS_TEST_H
