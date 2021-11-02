#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    private: 
	double operand; 
    public:
        Op(double value) : Base() {
	  operand = value;
        }
        virtual double evaluate() { return operand; }
        virtual std::string stringify() { 
      	  int oper = (int)operand;
	  return std::to_string(oper); }
};

class Rand : public Base {
    private:
       double operand;
    public:
        Rand(double value) : Base() {
        operand = rand() % 100;
 }
        virtual double evaluate() { return operand; }
        virtual std::string stringify() { 
	  int result = (int)operand;
	  return std::to_string(operand); }	

};

#endif //__OP_HPP__
