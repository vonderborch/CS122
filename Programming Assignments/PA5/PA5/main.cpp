#include "PA5.h"

int main (void)
{
	Bank progBank;
	Account tempAccount;
	int prog_state = 0, option = 0, temp = 0;
	string customerName, openDate;
	double accountBalance;

	while (prog_state >= 0)
	{
		option = display_menu (1, 0, ':', 1, 5, ";", "Basic Bank Application", "Main Menu",
			"Print Accounts;Add Account;Modify Account;Delete Account;Quit");
		// print accounts
		if (option == 1)
		{
			if (progBank.getBankSize () != 0)
			{
				progBank.printNodes ();
			}
			else
			{
				print_message (true, "No accounts in the Bank!");
			}
		}
		// add account
		else if (option == 2)
		{
			cout << "Customer Name: ";
			std::cin.ignore(300, '\n');
			cin >> customerName;
			cout << "Open Date: ";
			std::cin.ignore(300, '\n');
			cin >> openDate;
			cout << "Account Balance: ";
			std::cin.ignore(300, '\n');
			cin >> accountBalance;
			progBank.insertAtFront (customerName, accountBalance, openDate);
		}
		// modify account
		else if (option == 3)
		{
			cout << "Enter Account Number to Modify: ";
			std::cin.ignore(300, '\n');
			cin >> temp;
			cout << "Customer Name: ";
			std::cin.ignore(300, '\n');
			cin >> customerName;
			cout << "Account Balance: ";
			std::cin.ignore(300, '\n');
			cin >> accountBalance;
			progBank.modifyNode (temp, customerName, accountBalance);
		}
		// delete account
		else if (option == 4)
		{
			cout << "Enter Account Number to Modify: ";
			std::cin.ignore(300, '\n');
			cin >> temp;
			progBank.deleteAccount (temp);
		}
		// quit
		else
		{
			prog_state = -1;
		}
	}

	return 0;
}