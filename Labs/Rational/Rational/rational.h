#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

using std::cout;
using std::cin;
using std:endl;

class Rational
{
	public:
		// RULE OF 3 (BIG 3)
		// 1 - You NEED a copy constructor
		// 2 - You NEED a destructor
		// 3 - You NEED an overloaded assignment operator

		// Default Constructor
		Rational ();
		Rational Rational (&rhs);
		// Destructor
		~Rational();

		// Setters
		void setNumerator (int newNumerator);
		void setDenominator (int newDenominator);

		// getters (mutators, accessors)
		int getNumerator ();
		int getDenominator ();

		Rational addition (Rational num1, Rational num2);

	private:
		int mNumerator;
		int mDenomenator;
};

#endif