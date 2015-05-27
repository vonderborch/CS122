#ifndef PA5_H
#define PA5_H

#include <iostream>
#include <string>
#include "menu_system.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

class Account
{
	friend class Bank;

	public:
		Account ();
		Account (Account &rhs);
		Account (int newAccountNumber, string newCustomerName, double newAccountBalance, string newOpenDate, Account *pNewNext);
		~Account ();

		// setters
		void setAccountNumber (int newAccountNumber);
		void setCustomerName (string newCustomerName);
		void setAccountBalance (double newAccountBalance);
		void setOpenData (string newOpenDate);
		void setNextAccount (Account *newPNextAccount);

		// getters
		int getAccountName (void);
		string getCustomerName (void);
		double getAccountBalance (void);
		string getOpenDate (void);
		Account *getNextAccount (void);

		Account & operator= (Account &rhs);
	private:
		int accountNumber;
		string customerName;
		double accountBalance;
		string openDate;
		Account *pNextAccount;
};

class Bank
{
	public:
		Bank ();
		Bank (Bank &oldBank);
		~Bank ();

		int getBankSize (void);

		void printNodes ();
		bool insertAtFront (string newCustomerName, double newAccountBalance, string newOpenDate);
		bool modifyNode (int accountNumToEdit, string newCustomerName, double newAccountBalance);
		bool deleteList ();
		bool deleteAccount (int accountNumToDelete);
	private:
		Account *pFirstAccount;
		int bankSize;
};

void print_message (bool newLine, string message);

#endif