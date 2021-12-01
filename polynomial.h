/*************************
 * Class Polynomial       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

#include "expression.h"
#include <vector>
#include <algorithm>
#include <iomanip>

class Polynomial : public Expression {
public:

    //A constructor for building a polynomial from vector of doubles
    Polynomial(std::vector<double> coeff);

    //Conversion constructor for constant to polynomial
    Polynomial(double constant);

    //copy constructor
    Polynomial(const Polynomial& c);

    //Assignment operator
    Polynomial& operator=(Polynomial c);

    //addition-and-assignment operator
    Polynomial& operator+=(const Polynomial& c);
    
    //addition operator
    friend Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);

    //subscript operator
    double& operator[](const int e);
    double operator[](const int e) const;
    //to override from expression
    double operator()(double d) const override;
    virtual Polynomial* clone() const override;

    //check whether a destructor is needed
    //virtual ~Polynomial();

protected:
   // int degree;
    std::vector<double> coefficients;
    //double  coefficients;
    
private:

    void display(std::ostream& os) const;

};

#endif
