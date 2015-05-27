#include "lab2.h"

int main (void)
{
	int lab_state = 0, option = 0;
	char main_menu[][128] = {"Add Contact", "Remove Contact", "Edit Contact", "Print Contacts", "Store Contacts", "Load Contacts", "Exit Program"};
	Node *pList = NULL;
	Bool success = false;
	FILE *ioFile = NULL;

	ioFile = fopen ("contactList.txt", "r+");

	while (lab_state >= 0)
	{
		success = false;
		option = display_standard_menu (0, 1, 7, "Lab 2 - Dynamic Data Structures", main_menu);
		// Add Contact
		if (option == 1)
		{
			success = addContact (&pList);
			//success = addNonSortedContact (&pList);
			if (success)
			{
				printMessage ("New Contact Added!\n", true, false);
			}
			else
			{
				printMessage ("Failed to Add New Contact!\n", true, false);
			}
		}
		// Remove Contact
		else if (option == 2)
		{
		}
		// Edit Contact
		else if (option == 3)
		{
		}
		// Print Contacts
		else if (option == 4)
		{
			printContacts (pList);
		}
		// Store Contacts
		else if (option == 5)
		{
			storeContacts (pList, ioFile);
		}
		// Load Contacts
		else if (option == 6)
		{
			loadContacts (&pList, ioFile);
		}
		// Exit Program
		else if (option == 7)
		{
			lab_state = -1;
		}
	}

	fclose (ioFile);
	return 0;
}