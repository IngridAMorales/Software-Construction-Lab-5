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

TEST(DivTest, DivEvaluateZero) {
    Base* seven = new SevenOpMock();
    Base* zero = new ZeroOpMock();
    Div* test = new Div(zero, seven);

    EXPECT_EQ(test->evaluate(), "Invalid");
}

#endif
