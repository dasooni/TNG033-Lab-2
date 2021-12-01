/*********************************************************
 * Class Logarithm member functions implementation        *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "logarithm.h"
#include "polynomial.h"

Logarithm::Logarithm() : Expression(), c1{ 0.0 }, c2{ 1.0 }, b{ 2 }
{
	std::vector<double> coeff{0,1};
	E = new Polynomial{coeff};
	
}

Logarithm::Logarithm(const Expression& ex, double a1, double a2, int d) : Expression(),
c1{a1}, c2{a2}, b{d}
{
	E = ex.clone();
}

Logarithm::Logarithm(const Logarithm& L) : Expression(), c1{ L.c1 }, 
c2{ L.c2 }, b{L.b},  E{ L.E->clone() } {}

Logarithm& Logarithm::operator=(Logarithm L)
{
	std::swap(c1, L.c1);
	std::swap(c2, L.c2);
	std::swap(b, L.b);
	std::swap(E, L.E);

	return *this;
}

double Logarithm::operator()(double d) const
{
	double f = 0;
	f = c1 + c2 * (log((*E)(d)) / log(b)); //log_b(x) = log_d(x) / log_d(b) (change of base formula)
	return f;
}

void Logarithm::set_base(int k)
{
	b = k;
}

Logarithm* Logarithm::clone() const
{
	return(new Logarithm(*this));

}

Logarithm::~Logarithm()
{
	c1 = 0.0;
	c2 = 0.0;
	b = 0;
	delete E;
	E = nullptr;
}

void Logarithm::display(std::ostream& os) const
{
	os << std::fixed << std::setprecision(2);
	if (c2 < 0)
		os << c1 << " - " << abs(c2) << " * Log_" << b << "( " << *E << " )";
	else 
		os << c1 << " + " << c2 << " * Log_" << b << "( " << *E << " )";
}







