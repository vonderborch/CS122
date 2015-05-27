#include "creditReport.h"

CreditReport::CreditReport ()
{
		creditScore = 0;
		totalRealEstate = 0;
		creditCardDebt = 0;
		accountType = 0;
		accountAge = 0;
		timesAccessed = 0;
}
CreditReport::~CreditReport ()
{
}

// Setters
void CreditReport::setCreditScore (int newCreditScore)
{
	creditScore = newCreditScore;
}

void CreditReport::setTotalRealEstate (int newTotalRealEstate)
{
	totalRealEstate = newTotalRealEstate;
}

void CreditReport::setCreditCardDebt (int newCreditCardDebt)
{
	creditCardDebt = newCreditCardDebt;
}

void CreditReport::setAccountType (int newAccountType)
{
	accountType = newAccountType;
}

void CreditReport::setAccountAge (int newAccountAge)
{
	accountAge = newAccountAge;
}

void CreditReport::setTimesAccessed (int newTimesAccessed)
{
	timesAccessed = newTimesAccessed;
}

// getters
int CreditReport::getCreditScore ()
{
	return creditScore;
}

double CreditReport::getTotalRealEstate ()
{
	return totalRealEstate;
}

double CreditReport::getCreditCardDebt ()
{
	return creditCardDebt;
}

int CreditReport::getAccountType ()
{
	return accountType;
}

int CreditReport::getAccountAge ()
{
	return accountAge;
}

int CreditReport::getTimesAccessed ()
{
	return timesAccessed;
}