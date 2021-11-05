#ifndef __OPERATOR_TEST_HPP__
#define __OPERATOR_TEST_HPP__

#include "gtest/gtest.h"
#include "operator.hpp"


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
