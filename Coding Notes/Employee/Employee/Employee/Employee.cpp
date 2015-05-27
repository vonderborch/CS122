#include "Employee.h"

Employee::Employee (string newName, double newPayRate, double newHours)
{
	mName = newName;
	mPayRate = newPayRate;
	mHours = newHours;
}
		
Employee::~Employee ()
{
}

string Employee::getName ()
{
	return mName;
}

double Employee::getPayRate ()
{
	return mPayRate;
}

double Employee::getHours ()
{
	return mHours;
}

void Employee::setName (string newName)
{
	mName = newName;
}
		
void Employee::setPayRate (double newPayRate)
{
	mPayRate = newPayRate;
}
		
void Employee::setHours (double newHours)
{
	mHours = newHours;
}

double Employee::calculatePay ()
{
	return mHours * mPayRate;
}