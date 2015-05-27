#include "lab5.h"

Bool insertNode (TreeNode **pTree, char newLetter, char newMorse[16])
{
	TreeNode *pNew = NULL;
	Bool success = false;

	if (*pTree == NULL)
	{
		pNew = (TreeNode *) malloc (sizeof (TreeNode));
		if (pNew != NULL)
		{
			pNew->letter = newLetter;
			strcpy (pNew->morse, newMorse);

			pNew->pLeft = pNew->pRight = NULL;

			*pTree = pNew;

			success = true;
		}
	}
	else if (newLetter >= (*pTree)->letter)
	{
		insertNode (&((*pTree)->pRight), newLetter, newMorse);
	}
	else
	{
		insertNode (&((*pTree)->pLeft), newLetter, newMorse);
	}
	return success;
}

void printTree (TreeNode *pTree)
{
	if (pTree->pLeft != NULL)
	{
		printTree (pTree->pLeft);
	}
	printf ("%c: %s\n", pTree->letter, pTree->morse);
	if (pTree->pRight != NULL)
	{
		printTree (pTree->pRight);
	}
}

char *searchTree (TreeNode *pTree, char data)
{
	if (data < pTree->letter)
	{
		return treeSearch (pTree->pLeft, data);
	}
	else if (data > pTree->letter)
	{
		return treeSearch (pTree->pRight, data);
	}
	else
	{
		return pTree->morse;
	}
}

char *convertToMorse (TreeNode *pTree, char message[512])
{
}