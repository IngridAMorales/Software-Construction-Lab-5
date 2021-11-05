#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp" 
#include "operator.hpp"

class ThreeOpMock: public Base {
     public: 
	ThreeOpMock() { }

	virtual double evaluate() { return 3.5; }
	virtual std::string stringify() { return "3.5"; } 
};

class Add: public Base { 
    private: 
	Base* left; 
	Base* right; 
    public: 
	Add(Base* op, Base* oper) : Base() {
	   left = op; 
	   right = oper; 
 	}

	virtual double evaluate() { 
	  return this->left->evaluate() +  this->right->evaluate(); 
	}
	virtual std::string stringify() {
	  return "("+ this->left->stringify()+ "+"+ this->right->stringify()+ ")";
	}
}; 

#endif
