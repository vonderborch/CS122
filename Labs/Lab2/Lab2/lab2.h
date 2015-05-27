#ifndef LAB_2
#define LAB_2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common_functions.h"
#include "menu_system.h"

typedef struct contact
{
	char *lastName;
	char *firstName;
	char *phone;
	char *email;
	char *title;
} Contact;

typedef struct node
{
	Contact data;
	struct node *pNext;
} Node;

Bool addContact (Node **pList);
Bool addNonSortedContact (Node **pList);
Bool isEmpty (Node *pList);
Contact getContactInformation (void);
void printContacts (Node *pList);
void storeContacts (Node *pList, FILE *ioFile);
void loadContacts (Node **pList, FILE *ioFile);

#endif