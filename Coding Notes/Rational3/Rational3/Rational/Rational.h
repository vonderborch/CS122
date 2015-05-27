#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;


class Rational
{
	friend ostream & operator<< (ostream &output, Rational &rhs);

	public:

		// The rule of 3 - big 3
		// 1. Copy constructor
		// 2. Destructor
		// 3. Overloaded assignment operator

		// Constructor - ctor
		Rational (int newDenominator = 1, int newNumerator = 1);

		// copy constructo
		Rational (Rational &rhs);

		// Destructor - dtor
		~Rational ();

		// setters - mutators
		void setNumerator (int newNumerator);
		void setDenominator (int newDenominator);

		// getters - accessors
		int getNumerator ();
		int getDenominator ();


		Rational addition (Rational num1, Rational num2);

		Rational & operator= (Rational &rhs);
		Rational  operator+ (Rational &rhs);
		//bool operator> (Rational &rhs);
		// true, false

	private:
		int mNumerator;
		int mDenominator;
};