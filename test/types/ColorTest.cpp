//
// Created by thekatze on 24/02/2019.
//

#include <gtest/gtest.h>
#include <library/types/Color.h>
#include <library/log/Logger.h>

TEST(ColorTest, Addition) {
    Color white = Colors::RED + Colors::LIME + Colors::BLUE;

    ASSERT_TRUE(white == Colors::WHITE);
}

TEST(ColorTest, AdditionOverflow) {
    Color white = Colors::RED + Colors::LIME + Colors::BLUE + Colors::SILVER + Colors::GRAY;

    ASSERT_TRUE(white == Colors::WHITE);
}

TEST(ColorTest, Subtraction) {
    Color black = Colors::WHITE - Colors::RED - Colors::LIME - Colors::BLUE;

    ASSERT_TRUE(black == Colors::BLACK);
}

TEST(ColorTest, SubtractionOverflow) {
    Color black = Colors::WHITE - Colors::RED - Colors::MAROON - Colors::LIME - Colors::BLUE - Colors::SILVER;

    ASSERT_TRUE(black == Colors::BLACK);
}

TEST(ColorTest, Multiplication) {
    Color blue = Colors::BLUE * Colors::WHITE;

    ASSERT_TRUE(blue == Colors::BLUE);

    Color black = Colors::RED * Colors::BLACK;

    ASSERT_TRUE(black == Colors::BLACK);
}

TEST(ColorTest, Division) {
    Color white = Colors::LIME / Colors::BLACK;

    ASSERT_TRUE(white == Colors::WHITE);

    Color black = Colors::MAROON / Colors::WHITE;

    ASSERT_TRUE(black == Colors::BLACK);
}
