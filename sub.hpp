#ifndef __SUB_HPP__ 
#define __SUB_HPP__

#include "base.hpp"


class Sub: public Base {
  private: 
	Base* left; 
	Base* right; 
  public: 
	Sub(Base* op1, Base* op2) :Base() {
	  left = op1; 
	  right = op2; 
	}

	virtual double evaluate() { 
	  return this->left->evaluate() - this->right->evaluate(); 
	}
	virtual std::string stringify() { 
	  return "("+ this->left->stringify()+ "-"+ this->right->stringify()+ ")";
	}
}; 

#endif
