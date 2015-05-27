#ifndef LAB_3
#define LAB_3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "common_functions.h"
#include "menu_system.h"

/*
typedef enum bool
{
	false,
	true
} Bool; */

typedef struct nodeData
{
	double diskSize;
} NodeData;

typedef struct node
{
	NodeData data;
	struct node *pNext;
} Node;

Bool isEmpty (Node *pStack);
Bool push (Node **pStack, NodeData newData);
Bool pop (Node **pStack, NodeData *searchData);
Bool peek (Node *pStack, NodeData *peekData);
void printStack (Node *pStack, int pillarNum);
Bool isValid (Node *pPillars[3], int moveFrom, int moveTo);
Bool isVictory (Node *pPillars[3]);
NodeData popDisk (Node **pStack);

#endif