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


TEST(OperatorTest, OpEvaluateNonZero) {
    Base* seven = new SevenOpMock();
    Base* four = new FourOpMock();
    Mult* test = new Mult(seven, four); 

    EXPECT_DOUBLE_EQ(test->evaluate(), 33.75);
}

TEST(OperatorTest, OpEvaluateZero) {
    Base* seven = new SevenOpMock(); 
    Base* zero = new ZeroOpMock(); 
    Mult* test = new Mult(seven, zero); 

    EXPECT_DOUBLE_EQ(test->evaluate(), 0.0); 
} 
TEST(OperatorTest, OpEvaluateTwoNeg) { 
    Base* negseven = new NegOpMock(); 
    Base* negnumber = new NegOpMock(); 
    Mult* test = new Mult(negseven, negnumber); 

    EXPECT_DOUBLE_EQ(test->evaluate(), 56.25); 
}

TEST(OperatorTest, OpEvaluateNeg) {
    Base* seven = new NegOpMock(); 
    Base* four = new FourOpMock(); 
    Mult* test = new Mult(seven, four); 

    EXPECT_DOUBLE_EQ(test->evaluate(), -33.75); 
}
 
TEST(OperatorTest, OpStringify) {
    Base* seven = new SevenOpMock(); 
    Base* four = new FourOpMock(); 
    Mult* test = new Mult(seven, four); 

    EXPECT_EQ(test->stringify(), "(7.5*4.5)"); 
}

TEST(OperatorTest, OpStringifyZero) {
    Base* seven = new SevenOpMock(); 
    Base* zero = new ZeroOpMock(); 
    Mult* test = new Mult(seven, zero); 

    EXPECT_EQ(test->stringify(), "(7.5*0.0)"); 
}

TEST(OperatorTest, OpStringifyNeg) {
   Base* seven = new NegOpMock(); 
   Base* four = new FourOpMock(); 
   Mult* test = new Mult(seven, four); 

   EXPECT_EQ(test->stringify(), "(-7.5*4.5)"); 
}








#endif
