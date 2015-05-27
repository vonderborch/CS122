#include "Manager.h"

Manager::Manager (string newName, double newPayRate, double newHours, bool newSalariedEmployee) : Employee (newName, newPayRate, newHours)
{
	mIsASalariedEmployee = newSalariedEmployee;
}
		
Manager::~Manager ()
{
}

		/*string getName ();
		double getPayRate ();
		double getHours ();*/
bool Manager::getIsASalariedEmployee ()
{
	return mIsASalariedEmployee;
}

		/*void setName (string newName);
		void setPayRate (double newPayRate);
		void setHours (double newHours);*/
void Manager::setIsASalariedEmployee (bool newSalariedEmployee)
{
	mIsASalariedEmployee = newSalariedEmployee;
}

double Manager::calculatePay ()
{
	double payRate;

	if (mIsASalariedEmployee)
	{
		payRate = mPayRate;
		//payRate = Employee::getPayRate ();
	}
	else
	{
		payRate = Employee::calculatePay ();
	}

	return payRate;
}