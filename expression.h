/*************************
 * Class Expression       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <cmath>

constexpr double Epsilon = 1.0e-5;

// VIRTUAL FUNCTIONS: Is used to tell the compiler to use dynamic linkage or late binding, compiler determines the type of object during
// run time and then binds the function call
class Expression {
public:
    // Destructor
    virtual ~Expression() {
        --count_expressions;
    }

    // ADD OTHER MEMBER FUNCTIONS
    bool isRoot(const double& d) const; //is root check

    virtual double operator()(double d) const = 0; //operator

    virtual Expression* clone() const = 0; //cloneable

    friend std::ostream& operator<<(std::ostream& os, const Expression& E); //Display expression.



    // Return number of existing instances of class Expression
    // Used only for debug purposes
    static std::size_t get_count_expressions();

protected:
    // Default constructor
    Expression() {
        ++count_expressions;
    }

    // Copy constructor
    Expression(const Expression&) {
        ++count_expressions;
    }

    // Total number of existing expressions -- to help to detect bugs in the code
    static std::size_t count_expressions;

   
    virtual void display(std::ostream& os) const = 0;

    //1. Constructors cannot be virtual, so a virtual member is added to do the copying. This is the clone function.
    //2. 
};
