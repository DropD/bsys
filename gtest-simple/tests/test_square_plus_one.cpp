#include <gtest/gtest.h>
#include "square_plus_one.hpp"

TEST(SquarePlusOneTest, Integers) {
    EXPECT_EQ(gtest_simple::square_plus_one(1), 2);
    EXPECT_EQ(gtest_simple::square_plus_one(2), 5);
    EXPECT_EQ(gtest_simple::square_plus_one(3), 10);
}

TEST(SquarePlusOneTest, Floats) {
    EXPECT_FLOAT_EQ(gtest_simple::square_plus_one(1.1), 2.21);
    EXPECT_FLOAT_EQ(gtest_simple::square_plus_one(2.1), 5.41);
    EXPECT_FLOAT_EQ(gtest_simple::square_plus_one(3.1), 10.61);
}

TEST(SquarePlusOneTest, Integer2dElementWise) {
    auto result = gtest_simple::square_plus_one(gtest_simple::vec2di_ew(1, 2));
    EXPECT_EQ(result.x, 2);
    EXPECT_EQ(result.y, 4);
}
