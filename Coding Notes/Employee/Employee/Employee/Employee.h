#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Employee is a base class
class Employee
{
	public:
		Employee (string newName = "", double newPayRate = 8.55, double newHours = 0.0);
		~Employee ();

		string getName ();
		double getPayRate ();
		double getHours ();

		void setName (string newName);
		void setPayRate (double newPayRate);
		void setHours (double newHours);

		double calculatePay ();

	protected:
		string mName;
		double mPayRate;
		double mHours;
};

#endif