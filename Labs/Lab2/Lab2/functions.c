#include "lab2.h"

Bool addContact (Node **pList)
{
	Bool success = false;
	Node *pNew = NULL, *pCurrent = NULL, *pPrevious = NULL;

	pNew = (Node *) malloc (sizeof (Node));
	
	if (pNew != NULL)
	{
		// get contact information
		printMessage ("Contact Information?\n", false, false);
		pNew->data = getContactInformation ();
		pCurrent = *pList;
		pPrevious = pCurrent;
		// empty list
		if (isEmpty (*pList))
		{
			*pList = pNew;
		}
		// non-empty list first in line
		else if (strcmp (pCurrent->data.lastName, pNew->data.lastName) > 0)
		{
			pNew->pNext = *pList;
			*pList = pNew;
		}
		// non-empty list other case
		else
		{
			while ((!isEmpty(pCurrent)) && (strcmp ((pCurrent)->data.lastName, (pNew)->data.lastName) > 0))
			{
				pPrevious = pCurrent;
				pCurrent = pCurrent->pNext;
			}

			pNew = pPrevious->pNext;
			pPrevious->pNext = pNew;
		}

		success = true;
	}

	return success;
}

Bool addNonSortedContact (Node **pList)
{
	Bool success = false;
	Node *pNew = NULL;

	pNew = (Node *) malloc (sizeof (Node));
	
	if (pNew != NULL)
	{
		// get contact information
		printMessage ("Contact Information?\n", false, false);
		pNew->data = getContactInformation ();

		// insert contact
		pNew->pNext = *pList;
		*pList = pNew;

		success = true;
	}
	return success;
}

Bool isEmpty (Node *pList)
{
	Bool listEmpty = false;
	if (pList == NULL)
	{
		listEmpty = true;
	}
	return listEmpty;
}

Contact getContactInformation (void)
{
	Contact tempContactInfo;
	char firstName[32],
		 lastName[32],
		 phoneNum[32],
		 email[32],
		 title[32];
	Bool success = true;
	
	printf ("First Name? ");
	scanf ("%s", &firstName);
	printf ("Last Name? ");
	scanf ("%s", &lastName);
	printf ("Phone #? ");
	scanf ("%s", &phoneNum);
	printf ("Email? ");
	scanf ("%s", &email);
	printf ("Title? ");
	scanf ("%s", &title);

	tempContactInfo.firstName = (char *) malloc ((strlen (firstName) + 1) * sizeof (char));
	if (tempContactInfo.firstName == NULL)
	{
		success = false;
	}
	tempContactInfo.lastName = (char *) malloc ((strlen (lastName) + 1) * sizeof (char));
	if (tempContactInfo.lastName == NULL)
	{
		success = false;
	}
	tempContactInfo.phone = (char *) malloc ((strlen (phoneNum) + 1) * sizeof (char));
	if (tempContactInfo.phone == NULL)
	{
		success = false;
	}
	tempContactInfo.email = (char *) malloc ((strlen (email) + 1) * sizeof (char));
	if (tempContactInfo.email == NULL)
	{
		success = false;
	}
	tempContactInfo.title = (char *) malloc ((strlen (title) + 1) * sizeof (char));
	if (tempContactInfo.title == NULL)
	{
		success = false;
	}

	if (success == true)
	{ 
		strcpy (tempContactInfo.firstName, firstName);
		strcpy (tempContactInfo.lastName, lastName);
		strcpy (tempContactInfo.phone, phoneNum);
		strcpy (tempContactInfo.email, email);
		strcpy (tempContactInfo.title, title);
	}
	
	return tempContactInfo;
}

void printContacts (Node *pList)
{
	while (!isEmpty (pList))
	{
		printf ("%s %s %s\n", pList->data.title, pList->data.firstName, pList->data.lastName);
		printf ("Phone #: %s\n", pList->data.phone);
		printf ("Email: %s\n", pList->data.email);

		pList = pList->pNext;
		pause_clear (true, true);
	}
	printf ("Null\n");
}

void storeContacts (Node *pList, FILE *ioFile)
{
	while (!isEmpty (pList))
	{
		fprintf (ioFile, "%s %s %s %s %s\n", pList->data.firstName, pList->data.lastName,
			pList->data.phone, pList->data.email, pList->data.title);
		pList = pList->pNext;
	}
}

void loadContacts (Node **pList, FILE *ioFile)
{
}
