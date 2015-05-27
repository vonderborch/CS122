#ifndef LAB4_H
#define LAB4_H

#include <stdio.h>
#include <stdlib.h>

typedef struct queueNode
{
	char *strData;
	struct queueNode *pNext;
} QueueNode;

typedef struct queue
{
	QueueNode *pHead;
	QueueNode *pTail;
} Queue;

typedef enum bool
{
	false,
	true
} Bool;

Bool isNotEmpty (Queue q);
Bool enQueue (Queue *pQueue, char *newData);
Bool deQueue (Queue *pQueue);
void printQueueRecursive (Queue q);

#endif