#include "PA5.h"

Account::Account ()
{
	this->accountNumber = 1;
	this->customerName = "Hello";
	this->accountBalance = 0.0;
	this->openDate = "01/01/01";
	this->pNextAccount = NULL;
}

Account::Account (Account &rhs)
{
	this->accountNumber = rhs.accountNumber;
	this->customerName = rhs.customerName;
	this->accountBalance = rhs.accountBalance;
	this->openDate = rhs.openDate;
	this->pNextAccount = rhs.pNextAccount;
}

Account::Account (int newAccountNumber, string newCustomerName, double newAccountBalance,
				  string newOpenDate, Account *pNewNext)
{
	this->accountNumber = newAccountNumber;
	this->customerName = newCustomerName;
	this->accountBalance = newAccountBalance;
	this->openDate = newOpenDate;
	this->pNextAccount = pNewNext;
	if (this->accountBalance < 0)
	{
		this->accountBalance = 0;
		print_message (true, "Account balance below $0, reset to $0!");
	}
}

Account::~Account ()
{
	// does nothing
}

void Account::setAccountNumber (int newAccountNumber)
{
	accountNumber = newAccountNumber;
}

void Account::setCustomerName (string newCustomerName)
{
	customerName = newCustomerName;
}

void Account::setAccountBalance (double newAccountBalance)
{
	accountBalance = newAccountBalance;
}

void Account::setOpenData (string newOpenDate)
{
	openDate = newOpenDate;
}

void Account::setNextAccount (Account *newPNextAccount)
{
	*pNextAccount = *newPNextAccount;
}

int Account::getAccountName (void)
{
	return accountNumber;
}

string Account::getCustomerName (void)
{
	return customerName;
}

double Account::getAccountBalance (void)
{
	return accountBalance;
}

string Account::getOpenDate (void)
{
	return openDate;
}

Account* Account::getNextAccount (void)
{
	return pNextAccount;
}

Account & Account::operator= (Account &rhs)
{
	if (this != &rhs) // self-referential assignment
	{
		this->accountNumber = rhs.getAccountName ();
		this->customerName = rhs.getCustomerName ();
		this->accountBalance = rhs.getAccountBalance ();
		this->openDate = rhs.getOpenDate ();
		this->pNextAccount = rhs.getNextAccount ();
	}

	return (*this);
}

Bank::Bank ()
{
		bankSize = 0;
		pFirstAccount = NULL;
}

Bank::Bank (Bank &oldBank)
{
	Account *tempPtr = NULL, *memPtr = NULL, *currentPtr = NULL;

	bankSize = 0;

	tempPtr = oldBank.pFirstAccount; // Starting point for list
	                                   // that we want to copy
	while (tempPtr != NULL)
	{
		memPtr = new Account (*tempPtr);
		// Assume we are able to allocate memory successfully

		if (bankSize == 0) // "This" list object is currently empty
		{
			pFirstAccount = memPtr;
			currentPtr = pFirstAccount;
		}
		else
		{
			currentPtr->setNextAccount (memPtr);
			currentPtr = currentPtr->getNextAccount ();
		}

		tempPtr = tempPtr->getNextAccount ();

		bankSize++;
	}
}

Bank::~Bank ()
{
	deleteList ();
}

int Bank::getBankSize (void)
{
	return bankSize;
}

void Bank::printNodes ()
{
	Account *tempAccount;

	tempAccount = pFirstAccount;

	while (tempAccount != NULL)
	{
		cout << "Customer Number: " << tempAccount->accountNumber << " (" << tempAccount->customerName << " - " << tempAccount->openDate << ") - $" << tempAccount->accountBalance << endl;
		tempAccount = tempAccount -> getNextAccount ();
	}
}

bool Bank::insertAtFront (string newCustomerName, double newAccountBalance, string newOpenDate)
{
	Account *newNodePtr = NULL;

	bool success = true;

	newNodePtr = new Account (bankSize, newCustomerName, newAccountBalance, newOpenDate, NULL);

	if (newNodePtr == NULL)
	{
		success = false;
	}
	else
	{
		if (pFirstAccount == NULL) // empty list
		{
			pFirstAccount = newNodePtr;
		}
		else // not empty
		{
			newNodePtr -> setNextAccount (pFirstAccount);
			pFirstAccount = newNodePtr;
		}

		bankSize++;
	}

	return success;
}

bool Bank::modifyNode (int accountNumToEdit, string newCustomerName, double newAccountBalance)
{
	bool success = false;
	Account *previousPtr = NULL, *currentPtr = NULL, *tempPtr = NULL;

	currentPtr = pFirstAccount;

	if (pFirstAccount != NULL)
	{
		while ((currentPtr != NULL) && ((currentPtr ->getAccountName ()) != accountNumToEdit))
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr -> getNextAccount ();
		}
		currentPtr->accountBalance = newAccountBalance;
		currentPtr->customerName = newCustomerName;
		success = true;
	}
	return success;
}

bool Bank::deleteList ()
{
	Account *tempPtr = NULL, *deletePtr = NULL;
	bool success = false;

	tempPtr = this->pFirstAccount;

	while (tempPtr != NULL)
	{
		deletePtr = tempPtr;
		tempPtr = tempPtr->getNextAccount ();
		delete deletePtr;
		success = true;
	}

	return success;
}

bool Bank::deleteAccount (int accountNumToDelete)
{
	bool success = false;
	Account *previousPtr = NULL, *currentPtr = NULL, *tempPtr = NULL;

	currentPtr = pFirstAccount;

	if (pFirstAccount != NULL)
	{
		while ((currentPtr != NULL) && ((currentPtr ->getAccountName ()) != accountNumToDelete))
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr -> getNextAccount ();
		}

		if ((currentPtr != NULL) && (previousPtr != NULL)) // found the node, but is not first node
		{
			tempPtr = currentPtr;
			previousPtr -> setNextAccount (currentPtr -> getNextAccount ());
			delete tempPtr;
			success = true;
		}
		else if (currentPtr != NULL) // first node needs to be deleted
		{
			tempPtr = currentPtr;
			pFirstAccount = pFirstAccount -> getNextAccount ();
			delete tempPtr;
			success = true;
		}
	}
	return success;
}

void print_message (bool newLine, string message)
{
	cout << message;
	if (newLine)
		cout << endl;
}