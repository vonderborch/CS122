// This is the start of our Rational number example. It illustrates
// how to declare and use classes in C++.

// We will continue with this example for the next couple of lectures.
// We will use it to also motivate other important C++ and object oriented
// design techniques.

// Rev History: 2/22/12 - added copy constructor, overloaded assignment (=),
//                        and overloaded addition (+) operator

#include "Rational.h"

int main (void)
{
	// Instantiate an object
	Rational num1, num2(6, 7), result(8, 9);

	num1.setNumerator (5);

	cout << num1 << endl;

	// The overloaded + operator will eliminate these addition functions/methods
	//result = result.addition (num1, num2); // These are strange usages of addition
	//result = num1.addition (num1, num2); // These are strange usages of addition

	result = num1 + num2 + num2;

	cout << result << endl;

	//num1 = num1;

	return 0;
}