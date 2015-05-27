#include "testQueue.h"
#include "Queue.h"

void testEnqueueEmpty (void)
{
	Queue q = {NULL, NULL}; // Empty queue

	enqueue (&q, "string");

	printf ("Result: %s\n", q.pHead -> strData);
	printf ("Addresses: tail: %d, head: %d\n",
			q.pTail, q.pHead);
}

void testDequeueNonEmpty (void)
{
	Queue q = {NULL, NULL}; // Empty queue
	char *retStr = NULL;

	enqueue (&q, "string");

	printf ("Result: %s\n", q.pHead -> strData);

	retStr = dequeue (&q);
	
	printf ("Data dequeued: %s\n", q.pHead->strData);

	if (q.pTail == q.pHead == NULL)
	{
		printf ("Test case passed!\n");
	}
	else
	{
		printf ("Test case failed!\n");
	}
}
