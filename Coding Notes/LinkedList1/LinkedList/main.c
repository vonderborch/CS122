/* This is our start to implementing a linked list.

	Rev History: 1/18/12 - Implemented initList ()
*/

#include "LinkedList.h"

int main (void)
{
	char *pList = NULL;

	//pList = initList ();
	initList (&pList);

	printf ("Contents pList: %d\n", pList);

	return 0;
}