#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>

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

//void initQueue (QueueNode **pHead, QueueNode **pTail);
void initQueue (Queue *pQueue);
int isEmpty (Queue q);
void printQueueRecursive (Queue q);
int enqueue (Queue *pQueue, char *newStr);
void dequeue (Queue *pQueue);

#endif