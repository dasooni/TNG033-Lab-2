/*************************
 * Class Logarithm        *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <vector>

#include "expression.h"


class Logarithm : public Expression {
    
public:

    //Default constructor 
    Logarithm();

    //Constructor for logarithmic expression
    Logarithm(const Expression& ex, double a1, double a2, int d);

    //Copy constructor
    Logarithm(const Logarithm & L);

    //Assignment operator
    Logarithm& operator=(Logarithm L);

    //to return sum of the expression when x is equal to d
    virtual double operator()(double d) const override;

    void set_base(int k);

    //clone
    virtual Logarithm* clone() const override;

    //A destructor, check if needed
    virtual ~Logarithm();


protected:
    double c1, c2;
    int b;
    Expression* E;

    //display
    virtual void display(std::ostream& os) const override;
};
