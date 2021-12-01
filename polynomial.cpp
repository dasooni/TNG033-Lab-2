/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "polynomial.h"

//The compiler will provide a default constructor

//p[3] = 5, degree = 3, coef(i) = 5
Polynomial::Polynomial(std::vector<double> coeff) : Expression(), coefficients(coeff) {
}

Polynomial::Polynomial(double constant): Expression() {
	coefficients.push_back(constant);
}

Polynomial::Polynomial(const Polynomial& c): coefficients(c.coefficients)
{
	for (int i = 0; i < coefficients.size(); i++) {
		coefficients[i] = c.coefficients[i];

	}
}

Polynomial& Polynomial::operator=(Polynomial poly)
{
	//Polynomial copy{poly};
	//std::swap(copy.coefficients.size(),coefficients.size());
	//coefficients.size() = copy.coefficients.size();
	std::swap(coefficients, poly.coefficients);
	

	return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial& c) 
{
	//expand the number of coeffcients if necessary
	if (c.coefficients.size() > coefficients.size())
		coefficients.resize(c.coefficients.size(), 0.);

	//add to coeffcients
	for (int i = 0; i < c.coefficients.size(); i++) {
		coefficients[i] += c.coefficients[i];
	}

	return *this;

}

//THIS method requires override of clone and () operator!! from expression. Why??
//adds two polynomials together to a sum, i.e two vectors v1(i) + v2(i) = v3.
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs)
{
	//make a copy of lhs
	Polynomial res(lhs);
	
	//use += operator, as it does what we want
	res.operator+=(rhs);
	return res;
}

void Polynomial::display(std::ostream& os) const
{
	for (int i = 0; i < coefficients.size(); i++) {
		if (i == 0) {
			os << std::fixed << std::setprecision(2) << coefficients[i];
		}
		else if (coefficients[i] > 0) {
			os << std::fixed << std::setprecision(2) << " + " << (coefficients[i]) << " * X^" << i;
		}
		else if (coefficients[i] < 0) {
			os << std::fixed << std::setprecision(2) << " - " << abs(coefficients[i]) << " * X^" << i;
		}
		else {
			os << std::fixed << std::setprecision(2) << " + " << (coefficients[i]) << " * X^" << i;
		}
	}
}

double& Polynomial::operator[](const int e)
{
	return coefficients[e];
}

double Polynomial::operator[](const int e) const
{
	return coefficients[e];
}


//f(x), d = x. index i of vector gets multiplied by d^i
double Polynomial::operator()(double d) const {
	double f = 0.0;

	for (int i = 0; i < coefficients.size(); i++) {
		f += coefficients[i] * std::pow(d, i);
	}
	return f;
}

Polynomial* Polynomial::clone() const {
	return new Polynomial(*this);
}

//Class does not need an explicit destructor
// //A vectors destructor will be invoked automatically
// Thus we can let the compiler make a destructor for us
// Vector object is not dynamic either, so delete is not needed.
//Polynomial::~Polynomial()
//{
//	
//}
