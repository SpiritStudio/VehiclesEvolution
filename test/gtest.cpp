//
// Created by SpiritStudio on 04.12.18.
//

#include <gtest/gtest.h>
#include <math.h>
#include <Physics/Physics.h>

TEST(ExamplePhysicsTest, Physics) {
    EXPECT_FALSE(Physics::getInstance().allDead());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}