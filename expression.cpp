/*********************************************************
 * Class Expression member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "expression.h"

// Initialize the counter of the total number of existing Expressions
std::size_t Expression::count_expressions = 0;

// Used only for debug purposes
// Return number of existing Expressions
std::size_t Expression::get_count_expressions() {
    return Expression::count_expressions;
}

/* ************************* */

bool Expression::isRoot(const double& d) const {
    //Return d if its a root of f, *this is the expression, d is value. 
    //Compares smaller than Episolon, as we cannot compare with 0.
    return (fabs((*this)(d)) < Epsilon);
}

std::ostream& operator<<(std::ostream& os, const Expression& E)
{
    //Calling display function in expression so it can display both polynomial and lograithm
    E.display(os); 
    return os;
}
