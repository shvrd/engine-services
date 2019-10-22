//
// Created by thekatze on 22/10/2019.
//

#include <gtest/gtest.h>
#include <library/util/Math.h>

TEST(MathTest, PowerOfTwo) {
    EXPECT_EQ(Math::getNextPowerOfTwo(6), 8);
    EXPECT_EQ(Math::getNextPowerOfTwo(128), 128);
    EXPECT_EQ(Math::getNextPowerOfTwo(0), 1);
    EXPECT_EQ(Math::getNextPowerOfTwo(38342), 65536);
    EXPECT_EQ(Math::getNextPowerOfTwo(12), 16);
}
