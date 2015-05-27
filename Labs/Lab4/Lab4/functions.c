#include "lab4.h"

Bool isNotEmpty (Queue q)
{
	return (q.pHead != NULL);
}

Bool enQueue (Queue *pQueue, char *newData)
{
	Bool success = false;
	QueueNode *pNew = NULL;

	pNew = (QueueNode *) malloc (sizeof (QueueNode));
	
	if (pNew != NULL)
	{
		pNew -> strData = (char *) malloc (sizeof (char) * (strlen (newData) + 1)); 
		strcpy ((pNew->strData), newData);
		pNew->pNext = NULL;

		// Non empty node
		if (isNotEmpty (*pQueue))
		{
			pQueue->pTail->pNext = pNew;
		}
		// empty node
		else
		{
			pQueue->pHead = pNew;
		}
		pQueue->pTail = pNew;
		
		success = true;
	}

	return success;
}

Bool deQueue (Queue *pQueue)
{
	Bool success = false;
	QueueNode *pTemp = NULL;

	if (isNotEmpty (*pQueue))
	{
		// single node
		if (pQueue->pHead == pQueue->pTail)
		{
			pQueue->pTail = NULL;
		}
		pTemp = pQueue->pHead;
		pQueue->pHead = pQueue->pHead->pNext;
		free (pTemp->strData);
		free (pTemp);
		success = true;
	}

	return success;
}

void printQueueRecursive (Queue q)
{
	if (isNotEmpty (q))
	{
		printf ("%s -> ", (q.pHead)->strData);
		q.pHead = (q.pHead)->pNext;
		printQueueRecursive (q);
	}
	else
	{
		printf ("NULL\n");
	}
}