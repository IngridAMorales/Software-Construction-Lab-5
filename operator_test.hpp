#ifndef __OPERATOR_TEST_HPP__
#define __OPERATOR_TEST_HPP__

#include "gtest/gtest.h"
#include "operator.hpp"


TEST(DivTest, DivEvaluateNonZero) {
    Base* seven = new SevenOpMock();
    Base* four = new FourOpMock();
    Div* test = new Div(seven, four); 

    EXPECT_DOUBLE_EQ(test->evaluate(), 7.5/4.5);
}

TEST(DivTest, DivStringifyNonZero) {
    Base* seven = new SevenOpMock();
    Base* four = new FourOpMock();
    Div* test = new Div(seven, four);

    EXPECT_EQ(test->stringify(), "(7.5 / 4.5)");
}

TEST(DivTest, DivEvaluateNeg) {
    Base* seven = new NegOpMock();
    Base* four = new FourOpMock();
    Div* test = new Div(four, seven);

    EXPECT_DOUBLE_EQ(test->evaluate(), 4.5/-7.5);
}

TEST(DivTest, DivStringifyNeg) {
    Base* seven = new NegOpMock();
    Base* four = new FourOpMock();
    Div* test = new Div(four, seven);

    EXPECT_EQ(test->stringify(), "(4.5 / -7.5)");
}

TEST(DivTest, DivEvaluateZero) {
    Base* seven = new ZeroOpMock();
    Base* four = new FourOpMock();
    Div* test = new Div(seven, four);

    EXPECT_DOUBLE_EQ(test->evaluate(), 0.0);
}
TEST(DivTest, DivStringifyZero) {
    Base* seven = new ZeroOpMock();
    Base* four = new FourOpMock();
    Div* test = new Div(seven, four);

    EXPECT_EQ(test->stringify(), "(0.0 / 4.5)");
}
TEST(DivTest, DivStringifyZeroDiv) {
    Base* seven = new ZeroOpMock();
    Base* four = new FourOpMock();
    Div* test = new Div(four, seven);

    EXPECT_EQ(test->stringify(), "(4.5 / 0.0)");
}
TEST(DivTest, DivEvaluateZeroDiv) {
    Base* seven = new ZeroOpMock();
    Base* four = new FourOpMock();
    Div* test = new Div(four, seven);
    double resultans = test->evaluate();
    EXPECT_EQ(test->evaluate(), resultans);
}

#endif
