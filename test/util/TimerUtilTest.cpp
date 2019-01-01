//
// Created by thekatze on 22/12/2018.
//

#include <iostream>
#include <gtest/gtest.h>
#include <library/util/TimerUtils.h>

TEST(TimerUtilTest, FrameTimeForFPSTest) {
    EXPECT_EQ(TimerUtils::calculateFrameTimeForFPS(60), 16'666) << "Frame time isn't correct (60)";
    EXPECT_EQ(TimerUtils::calculateFrameTimeForFPS(30), 33'333) << "Frame time isn't correct (30)";
    EXPECT_EQ(TimerUtils::calculateFrameTimeForFPS(144), 6'944) << "Frame time isn't correct (144)";
}
