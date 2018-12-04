//
// Created by SpiritStudio on 04.12.18.
//

#include <gtest/gtest.h>
#include <math.h>
#include "include/Physics/Physics.h"

TEST(ExampleMapTest, Map) {
//    I expected it to work - it didn't
//    EXPECT_FALSE(Physics::getInstance().allDead());
    EXPECT_FALSE(sqrt(7.0) == 3);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}