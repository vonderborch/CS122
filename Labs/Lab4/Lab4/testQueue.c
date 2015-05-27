#include "testQueue.h"

void testEnqueueEmpty (void)
{
	Queue theQ = {NULL, NULL};

	enQueue (&theQ, "this is a string!");

	printf ("Result: %s\n", theQ.pHead->strData);
}

void testEnqueueNotEmpty (void)
{
	Queue theQ = {NULL, NULL};

	enQueue (&theQ, "this is a string!");

	printf ("Result: %s\n", theQ.pHead->strData);

	enQueue (&theQ, "another string!");

	printf ("Result: %s\n", theQ.pHead->pNext->strData);
}

void testDequeueNotEmpty (void)
{
	Queue theQ = {NULL, NULL};
	Bool success = false;

	enQueue (&theQ, "string");

	printf ("Result: %s\n", theQ.pHead->strData);

	success = deQueue (&theQ);

	if (success)
	{
		printf ("data dequeued.\n");
	}
	else
	{
		printf ("data not dequeued.\n");
	}
}

void testPrintEmpty (void)
{
	Queue theQ = {NULL, NULL};

	printQueueRecursive (theQ);
}

void testPrintNotEmpty (void)
{
	Queue theQ = {NULL, NULL};

	enQueue (&theQ, "this is a string!");
	enQueue (&theQ, "another string!");
	enQueue (&theQ, "one more string!");
	enQueue (&theQ, "all the strings!");
	
	printQueueRecursive (theQ);
}
