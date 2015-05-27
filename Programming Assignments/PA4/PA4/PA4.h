/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * PA4
 * Created: February 17th, 2011
 * Last Revised: February 22nd, 2012
 *
 * File Description: "PA4.h" contains the various includes and function
 *									prototypes which control the various functions.
 *********************************************************************************************/
#ifndef PA4_H
#define PA4_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common_functions.h"
#include "menu_system.h"

// Structs
typedef struct customerData
{
	int customerNumber;
	int serviceTime;
	int totalTime;
} CustomerData;

typedef struct queueNode
{
	CustomerData data;
	struct queueNode *pNext;
} QueueNode;

typedef struct queue
{
	QueueNode *pHead;
	QueueNode *pTail;
} Queue;

// functions.c
void pa4_main (int simulation_number, Bool isSaving);
int getArrivalTime (Bool isExpress);
int getServiceTime (Bool isExpress);
CustomerData clearData (void);
// queue_functions.c
void initializeQueue (Queue *pQueue);
Bool isEmpty (Queue theQ);
Bool enqueue (Queue *pQueue, CustomerData newData);
Bool dequeue (Queue *pQueue);
void printQueueRecursive (Queue theQ, FILE *outFile, Bool isSaving);

#endif