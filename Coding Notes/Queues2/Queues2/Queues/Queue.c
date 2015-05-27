#include "Queue.h"

/*void initQueue (QueueNode **pHead, QueueNode **pTail)
{
	*pHead = NULL;
	*pTail = NULL;

	// (*pHead)->
}*/

void initQueue (Queue *pQueue)
{
	pQueue -> pHead = NULL;
	pQueue -> pTail = NULL;
}


int isEmpty (Queue q)
{
	/*int status = 0; // Not empty

	if (q.pHead == NULL) // Empty
	{
		status = 1;
	}

	return status;*/

	return (q.pHead == NULL);
}

void printQueueRecursive (Queue q)
{
	if (!isEmpty (q)) // Recursive step
	{
		printf ("%s -> ", (q.pHead) -> strData);
		q.pHead = (q.pHead) -> pNext;
		printQueueRecursive (q);
	}
	else // Base case
	{
		printf ("NULL\n");
	}
}

int enqueue (Queue *pQueue, char *newStr)
{
	QueueNode *pMem = NULL;

	int status = 0; // Unsuccessful

	pMem = (QueueNode *) malloc (sizeof (QueueNode));

	if (pMem != NULL)
	{
		status = 1;
		//pMem -> strData = newStr; // Shallow copy
		pMem -> strData = (char *) malloc (sizeof (char) * (strlen (newStr) + 1)); 
		strcpy ((pMem -> strData), newStr);
		pMem -> pNext = NULL;

		// Empty queue
		if (isEmpty (*pQueue))
		{
			pQueue -> pHead = pMem;
		}
		else // Non empty
		{
			pQueue -> pTail -> pNext = pMem;
			//pQueue -> pTail = pMem;
		}

		pQueue -> pTail = pMem;
	}

	return status;
}

void dequeue (Queue *pQueue)
{
	QueueNode *pMem = NULL;

	if (!isEmpty (*pQueue))
	{
		if (pQueue->pHead == pQueue->pTail) // 1 node
		{
			pQueue->pTail = NULL;
		}
		pMem = pQueue->pHead;
		pQueue->pHead = pQueue->pHead->pNext;
		free (pMem->strData);
		free (pMem);
	}
}
