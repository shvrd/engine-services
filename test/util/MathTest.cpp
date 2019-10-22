//
// Created by thekatze on 22/10/2019.
//

#include <gtest/gtest.h>
#include <library/util/Math.h>

TEST(MathTest, NextPowerOfTwo) {
    EXPECT_EQ(Math::getNextPowerOfTwo(6), 8);
    EXPECT_EQ(Math::getNextPowerOfTwo(129), 256);
    EXPECT_EQ(Math::getNextPowerOfTwo(0), 1);
}
