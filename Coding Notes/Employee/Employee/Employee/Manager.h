#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>

#include "Employee.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Manager is a derived class, it's derived from Employee 
class Manager : public Employee // public inheritance
{
	public:
		Manager (string newName, double newPayRate, double newHours, bool newSalariedEmployee);
		~Manager ();

		/*string getName ();
		double getPayRate ();
		double getHours ();*/
		bool getIsASalariedEmployee ();

		/*void setName (string newName);
		void setPayRate (double newPayRate);
		void setHours (double newHours);*/
		void setIsASalariedEmployee (bool newSalariedEmployee);

		double calculatePay ();

	private:
		/*string mName;
		double mPayRate;
		double mHours;*/

		// This is a new attribute
		// This is not present in the Employee class
		bool mIsASalariedEmployee; 
};

#endif