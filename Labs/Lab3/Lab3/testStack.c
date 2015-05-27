#include "testStack.h"

void testIsEmpty (void)
{
	Node *pStack = NULL;
	pStack = (Node *) malloc (sizeof (Node));
	pStack->data.diskSize = 1.0;
	pStack->pNext = NULL;
	
	printf ("%d\n", isEmpty (pStack));
}

void testPrint (void)
{
	Node *pStack = NULL;
	pStack = (Node *) malloc (sizeof (Node));
	pStack->data.diskSize = 1.0;
	pStack->pNext = NULL;

	printStack (pStack, 1);
}

void testPush (void)
{
	Node *pStack = NULL;
	NodeData newData;
	Bool success = false;

	newData.diskSize = 1.0;

	success = push (&pStack, newData);
	if (success)
		printf ("Success: %d\n", pStack->data.diskSize);
	else
		printf ("Failure\n");
}

void testPop (void)
{
	Node *pStack = NULL;
	NodeData newData;
	Bool success = false;

	newData.diskSize = 1.0;

	success = push (&pStack, newData);
	if (success)
		printf ("Success, New Data: %d\n", pStack->data.diskSize);
	else
		printf ("Failure\n");
	success = pop (&pStack, &newData);
	if (success)
		printf ("Success, Node Deleted\n");
	else
		printf ("Failure 2\n");
}