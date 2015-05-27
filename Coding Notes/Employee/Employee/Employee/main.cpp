// This example introduces inheritance. Note that
// the Manager class is derived from the Employee class

#include <iostream>
#include <string>

#include "Employee.h"
#include "Manager.h"

int main (void)
{
	// Note that we can say that an Employee is not necessarily
	// a Manager, but a Manager is an Employee (this is inheritance!!!)
	Employee joe("joe", 5.67, 3.5);
	Manager bill("bill", 2000.00, 55, true);

	cout << "Employee Joe: " << joe.calculatePay () << endl;
	cout << "Manager bill: " << bill.calculatePay () << endl;

	return 0;
}