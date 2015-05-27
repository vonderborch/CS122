/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * PA4
 * Created: February 17th, 2011
 * Last Revised: February 22nd, 2012
 *
 * File Description: "queue_functions.c" contains the queue functions.
 *********************************************************************************************/
#include "PA4.h"

/*************************************************************
 * Function: initializeQueue ()
 * Created: February 17th, 2011
 * Last Revised: February 22nd, 2012
 * Description: This function initializes a queue
 * Preconditions: a queue needs to be initialized
 * Postconditions: a queue has been initialized
 *************************************************************/
void initializeQueue (Queue *pQueue)
{
	// assign the queue head/tail to nothing
	pQueue->pHead = NULL;
	pQueue->pTail = NULL;
}

/*************************************************************
 * Function: isEmpty ()
 * Created: February 17th, 2011
 * Last Revised: February 22nd, 2012
 * Description: This checks if aa queue is empty.
 * Preconditions: a queue needs to be checked
 * Postconditions: a queue has been checked
 *************************************************************/
Bool isEmpty (Queue theQ)
{
	// return whether the node is empty
	return (theQ.pHead == NULL);
}

/*************************************************************
 * Function: enqueue ()
 * Created: February 17th, 2011
 * Last Revised: February 22nd, 2012
 * Description: This function adds a node to the end of a queue
 * Preconditions: a node needs to be added
 * Postconditions: a node has been added
 *************************************************************/
Bool enqueue (Queue *pQueue, CustomerData newData)
{
	QueueNode *pNew = NULL;
	Bool success = false;

	// get memory for the new node
	pNew = (QueueNode *) malloc (sizeof (QueueNode));

	// if we successfully got memory, finish creating the node
	if (pNew != NULL)
	{
		pNew->data = newData;
		pNew->pNext = NULL;

		if (isEmpty (*pQueue))
		{
			pQueue->pHead = pNew;
		}
		else
		{
			pQueue->pTail->pNext = pNew;
		}

		pQueue->pTail = pNew;

		success = true;
	}

	return success;
}

/*************************************************************
 * Function: dequeue ()
 * Created: February 17th, 2011
 * Last Revised: February 22nd, 2012
 * Description: This function deletes the first node in a queue
 * Preconditions: a node needs to be dequeued
 * Postconditions: a node has been dequeued
 *************************************************************/
Bool dequeue (Queue *pQueue)
{
	QueueNode *pTemp = NULL;
	Bool success = false;

	// if the queue is not empty, delete the first node
	if (!isEmpty (*pQueue))
	{
		if (pQueue->pHead == pQueue->pTail)
		{
			pQueue->pTail = NULL;
		}

		pTemp = pQueue->pHead;
		pQueue->pHead = pQueue->pHead->pNext;
		free (pTemp);
	}

	return success;
}

/*************************************************************
 * Function: printQueueRecursive ()
 * Created: February 17th, 2011
 * Last Revised: February 22nd, 2012
 * Description: This function prints the queue in a recursive
 *					fashion
 * Preconditions: the queue needs to be printed
 * Postconditions: the queue has been printed
 *************************************************************/
void printQueueRecursive (Queue theQ, FILE *outFile, Bool isSaving)
{
	// as long as the current node is not empty, print it and then go to the next call of this function with the next node
	if (!isEmpty (theQ))
	{
		printf ("Customer #%d\nService Time: %d minutes.\n",
			theQ.pHead->data.customerNumber, theQ.pHead->data.serviceTime, theQ.pHead->data.totalTime);
		if (isSaving)
		{
			fprintf (outFile, "Customer #%d\nService Time: %d minutes.\n",
				theQ.pHead->data.customerNumber, theQ.pHead->data.serviceTime, theQ.pHead->data.totalTime);
		}
		theQ.pHead = theQ.pHead->pNext;
		printQueueRecursive (theQ, outFile, isSaving);
	}
}