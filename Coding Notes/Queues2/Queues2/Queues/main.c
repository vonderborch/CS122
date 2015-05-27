// Incomplete dynamic queue example w/ some test cases

#include "Queue.h"

int main (void)
{
	//QueueNode *pHead = NULL, *pTail = NULL;
	Queue q = {NULL, NULL};

	//initQueue (&pHead, &pTail);
	initQueue (&q);

	testEnqueueEmpty ();

	return 0;
}