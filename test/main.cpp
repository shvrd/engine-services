#include <gtest/gtest.h>
#include <library/GameContainer.h>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(ContainerTest, BasicFunctionality) {
    // GameContainer().start();
}