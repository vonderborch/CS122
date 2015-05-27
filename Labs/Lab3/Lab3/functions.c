#include "lab3.h"

Bool isEmpty (Node *pStack)
{
	Bool empty = false;
	if (pStack == NULL)
	{
		empty = true;
	}
	return empty;
}

Bool push (Node **pStack, NodeData newData)
{
	Node *pNew = NULL;
	Bool success = false;

	pNew = (Node *) malloc (sizeof (Node));

	if (!isEmpty (pNew))
	{
		pNew->data = newData;
		pNew->pNext = *pStack;
		*pStack = pNew;
		success = true;
	}

	return success;
}

Bool pop (Node **pStack, NodeData *searchData)
{
	Node *pTemp = NULL;
	Bool success = false;

	if (!isEmpty (*pStack))
	{
		pTemp = (*pStack)->pNext;
		*searchData = (*pStack)->data;
		free (*pStack);

		*pStack = pTemp;
		success = true;
	}
	
	return success;
}

Bool peek (Node *pStack, NodeData *peekData)
{
	Bool success = false;

	if (!isEmpty (pStack))
	{
		*peekData = pStack->data;
		success = true;
	}

	return success;
}

void printStack (Node *pStack, int pillarNum)
{
	printf ("Pillar %d: ", pillarNum);
	while (!isEmpty (pStack))
	{
		printf ("%.1lf", pStack->data.diskSize);
		if (pStack->pNext != NULL)
		{
			printf (" -> ");
		}
		pStack = pStack->pNext;
	}
	printf ("\n");
}

Bool isValid (Node *pPillars[3], int moveFrom, int moveTo)
{
	Bool valid = true, checkCycle = true;
	
	while ((valid == true) && (checkCycle == true))
	{
		// check if it is the same pillar
		if (moveFrom == moveTo)
			valid = false;
		// check if the disk to be moved is larger than the disk that is there (if one is there)
		if (pPillars[moveTo] != NULL)
		{
			if ((pPillars[moveFrom])->data.diskSize > (pPillars[moveTo])->data.diskSize)
			{
				valid = false;
			}
		}

		checkCycle = false;
	}

	return valid;
}

Bool isVictory (Node *pPillars[3])
{
	Bool victory = false;
	if (pPillars[0] == NULL)
	{
		if (pPillars[1] == NULL)
			victory = true;
		else if (pPillars[2] == NULL)
			victory = true;
	}
	return victory;
}

NodeData popDisk (Node **pStack)
{
	Node *pTemp = NULL;
	NodeData tempData;

	if (!isEmpty (*pStack))
	{
		pTemp = (*pStack)->pNext;
		tempData = (*pStack)->data;
		free (*pStack);

		*pStack = pTemp;
	}
	return tempData;
}