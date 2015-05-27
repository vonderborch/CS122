#include "Rational.h"

// Invoked implicitly when an object of type Rational is instantiated
Rational::Rational (int newDenominator, int newNumerator)

{
	mNumerator = newNumerator;
	mDenominator = newDenominator;
}


Rational::Rational (Rational &rhs)
{
	mNumerator = rhs.getNumerator ();
	mDenominator = rhs.getDenominator ();
}


// Invoked implicitly when an object of type Rational goes out of scope.
// Generally used to release dynamically allocated memory.
Rational::~Rational ()
{
	// Does nothing
}

Rational & Rational::operator= (Rational &rhs)
{
	if (this != &rhs) // self-referential assignment
	{
		mNumerator = rhs.getNumerator ();
		mDenominator = rhs.getDenominator ();
	}

	return (*this);
}

Rational Rational::operator+ (Rational &rhs)
{
	Rational result;

	result.setDenominator (mDenominator * rhs.getDenominator ());
	result.setNumerator ((this->getDenominator () * rhs.getNumerator ()) +
		                 (rhs.getDenominator () * this->getNumerator ()));

	return result; 
}

// This is a non-traditional use of addition - we will
// replace it with the overloaded + operator
Rational Rational::addition (Rational num1, Rational num2)
{
	Rational result;

	//num1.mDenominator
	result.setDenominator (num1.getDenominator () * num2.getDenominator ());
	result.setNumerator ((num1.getDenominator () * num2.getNumerator ()) +
		                 (num2.getDenominator () * num1.getNumerator ()));

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

ostream & operator<< (ostream &output, Rational &rhs)
{
	output << rhs.getNumerator () << "/" << rhs.getDenominator ();

	return output;
}