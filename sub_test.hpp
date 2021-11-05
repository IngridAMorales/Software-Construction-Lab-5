#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"
#include "sub.hpp"

TEST(SubTest, SubEvaluateNonzero) { 
  Base* seven = new SevenOpMock(); 
  Base* four = new FourOpMock(); 
  Base* three = new ThreeOpMock(); 
  Base* mult = new Mult(seven, four);
  Base* add = new Add(three, mult);
  Base* two = new TwoOpMock();  
  Sub* test = new Sub(add, two);

  EXPECT_DOUBLE_EQ(test->evaluate(), 34.75);  
}
TEST(SubTest, SubEvaluateNeg) {
  Base* seven = new SevenOpMock();
  Base* four = new FourOpMock();
  Base* three = new ThreeOpMock();
  Base* mult = new Mult(seven, four);
  Base* add = new Add(three, mult);
  Base* negseven = new NegOpMock();
  Sub* test = new Sub(add, negseven);

  EXPECT_DOUBLE_EQ(test->evaluate(), 44.75);
}
TEST(SubTest, SubStringifyNonzero){
  Base* seven = new SevenOpMock();
  Base* four = new FourOpMock();
  Base* three = new ThreeOpMock();
  Base* mult = new Mult(seven, four);
  Base* add = new Add(three, mult);
  Base* two = new TwoOpMock(); 
  Sub* test = new Sub(add, two);

  EXPECT_EQ(test->stringify(), "((3.5+(7.5*4.5))-2.5)"); 
}

TEST(SubTest, SubStringifyNeg) {
  Base* seven = new SevenOpMock();
  Base* four = new FourOpMock();
  Base* three = new ThreeOpMock();
  Base* mult = new Mult(seven, four);
  Base* add = new Add(three, mult);
  Base* negseven = new NegOpMock();
  Sub* test = new Sub(add, negseven);

  EXPECT_EQ(test->stringify(), "((3.5+(7.5*4.5))--7.5)"); 
}
TEST(SubTest, SubStringifyZero) {
  Base* seven = new SevenOpMock();
  Base* four = new FourOpMock();
  Base* three = new ThreeOpMock();
  Base* mult = new Mult(seven, four);
  Base* add = new Add(three, mult);
  Base* zero = new ZeroOpMock();
  Sub* test = new Sub(add, zero);

  EXPECT_EQ(test->stringify(), "((3.5+(7.5*4.5))-0.0)");
}
#endif
