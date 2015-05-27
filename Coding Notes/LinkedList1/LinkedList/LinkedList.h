#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>

typedef struct node
{
	char data;
	struct node *pNext; // self-referential
} Node;

//Node *initList (void);
void initList (Node **pList);


#endif