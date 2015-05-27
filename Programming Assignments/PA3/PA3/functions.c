/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * PA3
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 *
 * File Description: "functions.c" contains the sub-functions for the program.
 *********************************************************************************************/
#include "pa3.h"

/*************************************************************
 * Function: pa3_main ()
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 * Description: This function runs an evaluation/conversion
 * Input parameters: whether the expression should be saved
 * Returns: N/A
 * Preconditions: an expression needs to be converted/evaluated
 * Postconditions: an expression has been converted/evaluated
 *************************************************************/
void pa3_main (Bool isSaving)
{
	FILE *outFile = NULL;
	char infixString[128] = "", infixBackup[128],
		postfixString[128], postfixBackup[128];
	int endValue = 0.0;
	Bool success = false;

	// flush the buffer (just in case)
	_flushall ();
	fflush(stdin);

	// ask/get for an infix expression
	printf ("Expression to evaluate (positive integers, infix format)? ");
	while (!isdigit (infixString[0]))
	{
		gets (infixString);
	}
	printf ("Converting..");

	// make a backup copy of the inputted expression
	strcpy (infixBackup, infixString);
	printf (".");

	// convert infix to postfix
	success = infixConvertor (infixString, postfixString);
	if (success)
	{
		printf (".");

		// make a backup copy of the postfix expression
		strcpy (postfixBackup, postfixString);
		printf (".");

		// evaluate the expression
		printf (".Converted...Evaluating..");
		endValue = postfixEvaluation (&postfixString[0]);
		printf (".Evaluated!\n\n");

		// print the data
		printf ("%s = %s = %d\n", infixBackup, postfixBackup, endValue);

		// perform any necessary file operations if necessary
		if (isSaving)
		{
			// open the save file (or create one if necessary)
			outFile = fopen ("expressions.txt", "a");

			// print expression data
			fprintf (outFile, "%s = %s = %d\n", infixBackup, postfixBackup, endValue);

			// print that data has been saved
			printf ("Expression data has been saved!\n");

			// close file
			fclose (outFile);
		}
	}
	else
	{
		// if something went wrong, say so
		printf ("Failed to evaluate expression!\n");
	}
	// print a new line
	printf ("\n");
	// pause the screen
	pause_clear (true, false);
}

/*************************************************************
 * Function: infixConvertor ()
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 * Description: This function converts an infix expression
 *						to a postfix one
 * Input parameters: pointer to the infix/postfix expressions
 * Returns: True/False on success status
 * Preconditions: an infix expression needs to be converted
 * Postconditions: an infix expression has been converted
 *************************************************************/
Bool infixConvertor (char *infixEquation, char *postfixEquation)
{
	// variables
	char *pInfix, *pPostfix,
			tempChar;
	DataStack *tempStack = NULL;
	Bool success = false, isInCycle = true, isComplete = true;

	// setup the in/post-fix pointers
	pInfix = &infixEquation[0];
	pPostfix = &postfixEquation[0];

	// is a cycle going on?
	while (isInCycle == true)
	{
		// while one is...
		while (*pInfix && (isInCycle = true))
		{
			// while the next character is a space, skip it
			while (*pInfix == ' ')
			{
				pInfix++;
			}

			// if the next character is a digit...
			if (isdigit (*pInfix))
			{
				// while the next character is a digit...
				while (isdigit (*pInfix))
				{
					// assign this character to the next in the postfix string
					*pPostfix = *pInfix;
					// move to the next character on both strings
					pPostfix++;
					pInfix++;
				}
				// assign a space character to the next postfix character position
				// and move to the next one
				*pPostfix = ' ';
				pPostfix++;
			}

			// if the next character is a left parenthesis...
			if (*pInfix == '(')
			{
				// push the parenthesis into the stack
				success = push (&tempStack,*pInfix);
				// move to the next character
				pInfix++;
				// end the cycle if the push was unsuccessful
				if (!success)
					isInCycle = false;
			}

			// if the next character is a right parenthesis...
			if (*pInfix == ')')
			{
				// pop the last character from the stack
				tempChar = pop (&tempStack);
				// while the character is not a left parenthesis...
				while (tempChar != '(')
				{
					// assign the char to the postfix string
					*pPostfix = tempChar;
					// move to the next character spot
					pPostfix++;
					// add a space
					*pPostfix = ' ';
					// move to the next character spot
					pPostfix++;
					// pop the next char
					tempChar = pop (&tempStack);
				}
				// move to the next character spot
				pInfix++;
			}

			// if the next character is an operator...
			if (operatorType(*pInfix) > 0)
			{
				// if the stack has nothing in it...
				if (tempStack == NULL)
				{
					// push the char onto the stack
					success = push (&tempStack,*pInfix);
					// end the cycle if the push was unsuccessful
					if (!success)
						isInCycle = false;
				}
				// otherwise, we need to check for precedence...
				else
				{
					// pop a character from the stack
					tempChar = pop (&tempStack);
					// while the popped character is of greater precedence than the next character...
					while (operatorType (tempChar) >= operatorType (*pInfix))
					{
						// put the popped character onto the postfix string and move to the next to test
						*pPostfix = tempChar;
						pPostfix++;
						*pPostfix = ' ';
						pPostfix++;
						tempChar = pop (&tempStack);
					}
					// push the popped character into place
					success = push (&tempStack,tempChar);
					// end the cycle if the push was unsuccessful
					if (!success)
						isInCycle = false;
					// push the new character into place
					success = push (&tempStack,*pInfix);
					// end the cycle if the push was unsuccessful
					if (!success)
						isInCycle = false;
				}
				// move to the next character spot
				pInfix++;
			}
		}
		// move through the stack while it was not empty and add the
		// characters from it onto the postfix string
		while (tempStack != NULL)
		{
			tempChar = pop(&tempStack);
			*pPostfix = tempChar;
			pPostfix++;
			*pPostfix = ' ';
			pPostfix++;
		}
		*pPostfix = '\0';
		isInCycle = false;
	}
	// if any push was unsuccessful...
	if (!success)
		isComplete = false;
	// return the success of the converter
	return isComplete;
}

/*************************************************************
 * Function: operatorType ()
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 * Description: The operator priority needs to be know
 * Input parameters: the character to be tested
 * Returns: the value of the operator
 * Preconditions: a operator's priority is needed
 * Postconditions: a operator's priority is gotten
 *************************************************************/
int operatorType (char temp)
{
	// variable
	int tempValue = 0;
	// is the operator high priority?
	if ((temp == '*') || (temp == '/') || (temp == '%'))
	{
		tempValue = 2;
	}
	// is the operator low priority?
	else if ((temp == '+') || (temp == '-'))
	{
		tempValue = 1;
	}
	// return the value of the operator
	return tempValue;
}

/*************************************************************
 * Function: isOperator ()
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 * Description: This function determines whether the
 *							passed character is a operator
 * Input parameters: the character
 * Returns: True/False on character status
 * Preconditions: a character needs to be checked
 * Postconditions: a character has been checked
 *************************************************************/
Bool isOperator (char temp)
{
	// variable
	Bool tempValue = false;
	// is the character an operator?
	if((temp == '+') || (temp == '-') || (temp == '*') ||
		(temp == '/') || (temp == '%'))
		tempValue = true;
	// return whether it is an operator or not
	return tempValue;
}

/*************************************************************
 * Function: push ()
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 * Description: pushes a node onto the regular stack
 * Input parameters: the regular stack
 * Returns: the new version of the stack
 * Preconditions: a regular node needs to be pushed
 * Postconditions: an regular node has been pushed
 *************************************************************/
Bool push (DataStack **pStack, char newData)
{
	// variables
	Bool success = false;
	DataStack *pNew = NULL;

	// allocate memory for the new node
	pNew = (DataStack *) malloc (sizeof (DataStack));

	// if memory was successfully allocated...
	if (pNew != NULL)
	{
		// assign the new data to the new node
		pNew->data = newData;

		// set the next node to be the old stacks top node
		pNew->pNext = *pStack;
		// set the new node to the top of the stack
		*pStack = pNew;

		// say it was a success
		success = true;
	}

	// return success boolean
	return success;
}

/*************************************************************
 * Function: pop ()
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 * Description: Pops a node from the regular stack
 * Input parameters: the regular stack
 * Returns: the regular popped off
 * Preconditions: a regular node needs to be popped
 * Postconditions: an regular node has been popped
 *************************************************************/
char pop (DataStack **pStack)
{
	// variables
	char tempChar = '\0';
	DataStack *pTemp = NULL;

	// if the stack exists...
	if (*pStack != NULL)
	{
		// assign the current top of the stack to a temp node
		pTemp = *pStack;
		// assign the data to the temp variable
		tempChar = pTemp->data;
		// set the top of the stack to being the next node
		*pStack = (*pStack)->pNext;
		// free the old first node
		free (pTemp);
	}

	// return the node's data
	return tempChar;
}

/*************************************************************
 * Function: isEmpty ()
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 * Description: This function determines if the stack is empty
 * Input parameters: the stack
 * Returns: True/False on node empty or not
 * Preconditions: the stack needs to be determined on
 *							its emptiness
 * Postconditions: the stack has been determined on
 *							its emptiness
 *************************************************************/
Bool isEmpty (DataStack *pStack)
{
	// return whether the stack is there or not
	return (pStack != NULL);
}

/*************************************************************
 * Function: postfixEvaluation ()
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 * Description: This function evaluates a postfix expression
 * Input parameters: the postfix expression
 * Returns: the value of the expression
 * Preconditions: an expression needs to be evaluated
 * Postconditions: an expression has been evaluated
 *************************************************************/
int postfixEvaluation (char *postfixEquation)
{
	// variables
	char *pPostfix, tempMulti[256] = "", tempSingle;
	IntDataStack *tempStack = NULL;
	int value = 0, numA = 0, numB = 0, i = 0, j = 0;

	// setup the infix pointers
	pPostfix = &postfixEquation[0];

	// while we're not at the end of the postfix string...
	while (*pPostfix != '\0')
	{
		// remove any spaces if necessary...
		while(*pPostfix == ' ')
		{
			pPostfix++;
		}
		// if the next character is a digit...
		if(isdigit(*pPostfix))
		{
			// build the integer...
			while (isdigit(*pPostfix))
			{
				tempSingle = *pPostfix;
				tempMulti[i] = tempSingle;
				*pPostfix++;
				i++;
			}
			// push the built integer onto the stack
			pushInt(&tempStack, atoi(tempMulti));
			// move through the integer builder array and clear it
			for (j = 0; j <= i; j++)
			{
				tempMulti[j] = '\0';
			}
			// set i to 0
			i = 0;
		}
		// otherwise...
		else
		{
			// if the next character is an operator...
			if ((*pPostfix == '+') || (*pPostfix == '-') || (*pPostfix == '/') ||
				(*pPostfix == '*') || (*pPostfix == '%'))
			{
				// pop off the last two numbers from the stack
				numB = popInt(&tempStack);
				numA = popInt(&tempStack);

				// if the operator is a +, add the two numbers and push the value onto the stack
				if (*pPostfix == '+')
				{
					value = numA + numB;
					pushInt(&tempStack,value);
				}
				// if the operator is a -, add the two numbers and push the value onto the stack
				else if (*pPostfix ==  '-')
				{
					value = numA - numB;
					pushInt(&tempStack,value);
				}
				// if the operator is a *, add the two numbers and push the value onto the stack
				else if (*pPostfix ==  '*')
				{
					value = numA * numB;
					pushInt(&tempStack,value);
				}
				// if the operator is a /, add the two numbers and push the value onto the stack
				else if (*pPostfix ==  '/')
				{
					value = numA / numB;
					pushInt(&tempStack,value);
				}
				// if the operator is a %, add the two numbers and push the value onto the stack
				else if (*pPostfix ==  '%')
				{
					value = numA % numB;
					pushInt(&tempStack,value);
				}
				// otherwise, say that there was a problem evaluating the expression...
				else
				{
					printf ("Failed to evaluate Expression!\n");
					return -1;
				}
			}
		}
		// if the character is not a null character move to the next
		if (*pPostfix != '\0')
		{
			pPostfix++;
		}
	}
	// pop the final value off the  stack and return it...
	value = popInt(&tempStack);
	return value;
}

/*************************************************************
 * Function: pushInt ()
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 * Description: pushes a node onto the int stack
 * Input parameters: the int stack
 * Returns: the new version of the stack
 * Preconditions: a int node needs to be pushed
 * Postconditions: an int node has been pushed
 *************************************************************/
Bool pushInt (IntDataStack **pStack, int newData)
{
	// variables
	Bool success = false;
	IntDataStack *pNew = NULL;

	// allocate memory for the new node
	pNew = (IntDataStack *) malloc (sizeof (IntDataStack));

	// if memory was successfully allocated...
	if (pNew != NULL)
	{
		// assign the new data to the new node
		pNew->data = newData;

		// set the next node to be the old stacks top node
		pNew->pNext = *pStack;
		// set the new node to the top of the stack
		*pStack = pNew;

		// say it was a success
		success = true;
	}

	// return success boolean
	return success;
}

/*************************************************************
 * Function: popInt ()
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 * Description: Pops a node from the int stack
 * Input parameters: the int stack
 * Returns: the int popped off
 * Preconditions: a int node needs to be popped
 * Postconditions: an int node has been popped
 *************************************************************/
int popInt (IntDataStack **pStack)
{
	// variables
	int temp = 0;
	IntDataStack *pTemp = NULL;

	// if the node is not empty...
	if (*pStack != NULL)
	{
		// assign the temp node to the old top node
		pTemp = *pStack;
		// assign the data of that node to a temp variables
		temp = pTemp->data;
		// make the top node equal to the Stacks second from the top node
		*pStack = (*pStack)->pNext;
		// clear the old top node
		free (pTemp);
	}

	// return the popped data
	return temp;
}