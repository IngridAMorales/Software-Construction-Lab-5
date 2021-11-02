#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    public:
        Op(double value) : Base() { }
        virtual double evaluate() { return 0.0; }
        virtual std::string stringify() { return ""; }
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
