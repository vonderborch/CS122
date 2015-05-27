#ifndef LAB5_H
#define LAB5_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum bool
{
	false,
	true
} Bool;

typedef struct treeNode
{
	char letter;
	char morse[16];
	struct treeNode *pLeft;
	struct treeNode *pRight;
} TreeNode;

Bool insertNode (TreeNode **pTree, char newLetter, char newMorse[16]);
void printTree (TreeNode *pTree);
char *searchTree (TreeNode *pTree, char data);
char *convertToMorse (TreeNode *pTree, char message[512]);

#endif