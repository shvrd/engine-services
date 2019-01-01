//
// Created by thekatze on 16/12/2018.
//

#include <iostream>
#include <gtest/gtest.h>
#include <library/util/Timer.h>

TEST(TimerTest, StartStop) {
    Timer timer;
    unsigned long startTime = timer.get();

    std::cout << "StartTime: " << startTime << std::endl;

    unsigned long endTime = timer.get();

    std::cout << "EndTime: " << endTime << std::endl;

    EXPECT_TRUE(startTime <= endTime) << "Endtime is bigger than starttime";
}

TEST(TimerTest, Waiting) {
    Timer timer;
    unsigned long startTime = timer.get();

    std::cout << "StartTime: " << startTime << std::endl;

    unsigned long waitTime = 50000L;
    timer.wait(waitTime);

    unsigned long endTime = timer.get();

    std::cout << "EndTime: " << endTime << std::endl;

    EXPECT_TRUE(startTime + waitTime <= timer.get()) << "Endtime is bigger than starttime + 50000ys";
}
