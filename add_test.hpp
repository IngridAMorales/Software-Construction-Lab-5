#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"
#include "add.hpp"

TEST(AddTest, AddEvaluateNonzero) {
  Base* seven = new SevenOpMock(); 
  Base* four = new FourOpMock(); 
  Base* three = new ThreeOpMock(); 
  Base* mult = new Mult(seven, four); 
  Add* test = new Add(three, mult); 

  EXPECT_DOUBLE_EQ(test->evaluate(), 37.25); 
}
TEST(AddTest, AddEvaluateNeg) {
  Base* seven = new SevenOpMock();
  Base* four = new FourOpMock();
  Base* negseven = new NegOpMock();
  Base* mult = new Mult(seven, four);
  Add* test = new Add(negseven, mult); 

  EXPECT_DOUBLE_EQ(test->evaluate(), 26.25); 
}

TEST(AddTest, AddStringifyNonzero) { 
  Base* seven = new SevenOpMock();
  Base* four = new FourOpMock();
  Base* three = new ThreeOpMock();
  Base* mult = new Mult(seven, four);
  Add* test = new Add(three, mult); 

  EXPECT_EQ(test->stringify(), "(3.5+(7.5*4.5))"); 
}
TEST(AddTest, AddStringifyNeg) {
  Base* seven = new SevenOpMock();
  Base* four = new FourOpMock();
  Base* negseven = new NegOpMock();
  Base* mult = new Mult(seven, four);
  Add* test = new Add(negseven, mult);

  EXPECT_EQ(test->stringify(), "(-7.5+(7.5*4.5))"); 
}

#endif
