//
// Created by thekatze on 24/02/2019.
//

#include <gtest/gtest.h>
#include <library/log/Logger.h>

TEST(LoggerTest, Info) {
    Logger::info("This is an informational message!");
}

TEST(LoggerTest, Warning) {
    Logger::info("This is a warning message!");
}

TEST(LoggerTest, Error) {
    Logger::info("This is an error message!");
}
