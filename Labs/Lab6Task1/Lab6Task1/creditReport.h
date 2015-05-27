#ifndef CREDIT_H
#define CREDIT_H

#include <iosteam>

using std::cout;
using std::cin;
using std::endl;

class CreditReport
{
	public:
		CreditReport ();
		~CreditReport ();

		// Setters
		void setCreditScore (int newCreditScore);
		void setTotalRealEstate (int newTotalRealEstate);
		void setCreditCardDebt (int newCreditCardDebt);
		void setAccountType (int newAccountType);
		void setAccountAge (int newAccountAge);
		void setTimesAccessed (int newTimesAccessed);

		// getters (mutators, accessors)
		int getCreditScore ();
		double getTotalRealEstate ();
		double getCreditCardDebt ();
		int getAccountType ();
		int getAccountAge ();
		int getTimesAccessed ();

	private:
		int creditScore;
		double totalRealEstate;
		double creditCardDebt;
		int accountType;
		int accountAge;
		int timesAccessed;
}

#endif