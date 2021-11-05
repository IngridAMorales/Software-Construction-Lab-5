#ifndef __POWER_HPP__
#define __POWER_HPP__

#include "base.hpp"
#include "operator.hpp"
#include <math.h>


class Pow : public Base{
	private:
	 Base* left;
	 Base* right;

	public:
	 Pow(Base* op1, Base* op2) : Base(){
		left = op1;
		right = op2;

}
	virtual double evaluate(){
	 return pow(this->left->evaluate(),this->right->evaluate());
}
	virtual std::string stringify(){
		return "("+ this->left->stringify() + " ** " + this->right->stringify()+")"; 
}

};

#endif
