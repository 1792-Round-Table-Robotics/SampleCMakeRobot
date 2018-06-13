#include <iostream>

#include "gtest/gtest.h"

TEST(ExampleTest, HelloTest) {
    int i = 0;
    int i2 = i + 1;
    EXPECT_EQ(1, i2);
}