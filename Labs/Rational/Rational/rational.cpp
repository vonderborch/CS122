#include "rational.h"

// default constructor
Rational::Rational ()
{
	mNumerator = 1;
	mDenominator = 1;
}

Rational::Rational Rational (&rhs)
{
	mNumerator = rhs.getNumerator ();
	mDenominator = rhs.getDenominator ();
}

// Destructor
Rational::~Rational()
{
	// Does nothing yet...
}

Rational Rational::addition (Rational num1, Rational num2)
{
	Rational result;

	result.setDenominator ((num1.getDenominator ()) * (num2.getDenominator ()));
	result.setNumerator ((num1.getNumerator ()) * (num2.getNumerator ()) + 
		((num2.getDenominator ()) * (num1.getDenominator())));

	return result;
}

void Rational::setNumerator (int newNumerator)
{
	mNumerator = newNumerator;
}

void Rational::setDenominator (int newDenominator)
{
	mDenominator = newDenominator;
}

int Rational::getNumerator ()
{
	return mNumerator;
}

int Rational::getDenominator ()
{
	return mDenominator;
}