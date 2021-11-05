#ifndef __POWER_TEST_HPP__
#define __POWER_TEST_HPP__

#include "gtest/gtest.h"
#include "power.hpp"
#include <math.h>

TEST(PowTest, PowEvaluateNonZero) {
    Base* seven = new SevenOpMock();
    Base* four = new FourOpMock();
    Pow* test = new Pow(seven, four);

    EXPECT_DOUBLE_EQ(test->evaluate(), pow(7.5,4.5));
}
TEST(PowTest, PowEvaluateZero) {
    Base* seven = new SevenOpMock();
    Base* four = new FourOpMock();
    Pow* test = new Pow(seven, four);

    EXPECT_DOUBLE_EQ(test->evaluate(), pow(7.5,4.5));
}
TEST(PowTest, PowStringifyZero) {
    Base* zero = new ZeroOpMock();
    Base* four = new FourOpMock();
    Pow* test = new Pow(zero, four);

    EXPECT_EQ(test->stringify(),"(0.0 ** 4.5)");
}
TEST(PowTest, PowStringifyNonZero) {
    Base* seven = new SevenOpMock();
    Base* four = new FourOpMock();
    Pow* test = new Pow(seven, four);

    EXPECT_EQ(test->stringify(), "(7.5 ** 4.5)");
}
TEST(PowTest, PowEvaluateNeg) {
    Base* seven = new NegOpMock();
    Base* four = new FourOpMock();
    Pow* test = new Pow(four, seven);

    EXPECT_DOUBLE_EQ(test->evaluate(), pow(4.5,-7.5));
}
TEST(PowTest, PowStringifyNeg) {
    Base* seven = new NegOpMock();
    Base* four = new FourOpMock();
    Pow* test = new Pow(four, seven);

    EXPECT_EQ(test->stringify(),"(4.5 ** -7.5)");
}

TEST(PowTest, PowEvaluateNegPow) {
    Base* seven = new NegOpMock();
    Base* two = new TwoOpMock();
    Pow* test = new Pow(seven, two);
    
    EXPECT_EQ(test->evaluate(), pow(-7.5,2.0));
}
TEST(PowTest, PowStringifyNegPow) {
    Base* seven = new NegOpMock();
    Base* two = new TwoOpMock();
    Pow* test = new Pow(seven, two);

    EXPECT_EQ(test->stringify(), "(-7.5 ** 2.0)");
}

#endif
