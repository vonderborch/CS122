/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * PA3
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 *
 * File Description: "PA3.h" contains the includes and definitions of the various
 *									peices needed for the program.
 *********************************************************************************************/
#ifndef PA3_H
#define PA3_H

// included libraries
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common_functions.h"
#include "menu_system.h"

// typedefs
typedef struct dataStack
{
	char data;
	struct dataStack *pNext;
} DataStack;
typedef struct intDataStack
{
	int data;
	struct intDataStack *pNext;
} IntDataStack;

// functions
void pa3_main (Bool isSaving);
Bool infixConvertor (char *infixEquation, char *postfixEquation);
int operatorType (char temp);
Bool isOperator (char temp);
Bool push (DataStack **pStack, char newData);
char pop (DataStack **pStack);
Bool isEmpty (DataStack *pStack);
int postfixEvaluation (char *postfixEquation);
Bool pushInt (IntDataStack **pStack, int newData);
int popInt (IntDataStack **pStack);

#endif