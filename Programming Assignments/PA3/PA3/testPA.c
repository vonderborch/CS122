/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * PA3
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 *
 * File Description: "testPA.c" contains the test functions
 *********************************************************************************************/
#include "testPA.h"

/*************************************************************
 * Function: testoperatorType ()
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 * Description: This function tests the operatorType function
 * Input parameters: N/A
 * Returns: N/A
 * Preconditions: function needs to be tested
 * Postconditions: function has been tested
 *************************************************************/
void testoperatorType (void)
{
	printf ("+: %d\n", operatorType ('+'));
	printf ("-: %d\n", operatorType ('-'));
	printf ("*: %d\n", operatorType ('*'));
	printf ("/: %d\n", operatorType ('/'));
	printf ("%: %d\n", operatorType ('%'));
	printf ("A: %d\n", operatorType ('A'));
}

/*************************************************************
 * Function: testisOperator ()
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 * Description: This function tests the isOperator function
 * Input parameters: N/A
 * Returns: N/A
 * Preconditions: function needs to be tested
 * Postconditions: function has been tested
 *************************************************************/
void testisOperator (void)
{
	printf ("+: %d\n", isOperator ('+'));
	printf ("-: %d\n", isOperator ('-'));
	printf ("*: %d\n", isOperator ('*'));
	printf ("/: %d\n", isOperator ('/'));
	printf ("%: %d\n", isOperator ('%'));
	printf ("A: %d\n", isOperator ('A'));
}

/*************************************************************
 * Function: testpush ()
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 * Description: This function tests the push function
 * Input parameters: N/A
 * Returns: N/A
 * Preconditions: function needs to be tested
 * Postconditions: function has been tested
 *************************************************************/
void testpush (void)
{
	DataStack *pTemp = NULL;
	printf ("Successful Push? %d\n", push (&pTemp, 'a'));
	printf ("Successful Push? %d\n", push (&pTemp, 'b'));
}

/*************************************************************
 * Function: testpop ()
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 * Description: This function tests the pop function
 * Input parameters: N/A
 * Returns: N/A
 * Preconditions: function needs to be tested
 * Postconditions: function has been tested
 *************************************************************/
void testpop (void)
{
	DataStack *pTemp = NULL;
	printf ("Successful Push? %d\n", push (&pTemp, 'a'));
	printf ("Popped Data? %c\n", pop (&pTemp));
}

/*************************************************************
 * Function: testisEmpty ()
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 * Description: This function tests the isEmpty function
 * Input parameters: N/A
 * Returns: N/A
 * Preconditions: function needs to be tested
 * Postconditions: function has been tested
 *************************************************************/
void testisEmpty (void)
{
	DataStack *pTemp = NULL;
	printf ("Is Empty?", isEmpty (pTemp));
	printf ("Successful Push? %d\n", push (&pTemp, 'a'));
	printf ("Is Empty?", isEmpty (pTemp));
}

/*************************************************************
 * Function: testpushInt ()
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 * Description: This function tests the pushInt function
 * Input parameters: N/A
 * Returns: N/A
 * Preconditions: function needs to be tested
 * Postconditions: function has been tested
 *************************************************************/
void testpushInt (void)
{
	IntDataStack *pTemp = NULL;
	printf ("Successful Push? %d\n", pushInt (&pTemp, 1));
	printf ("Successful Push? %d\n", pushInt (&pTemp, 2));
}

/*************************************************************
 * Function: testpopInt ()
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 * Description: This function tests the popInt function
 * Input parameters: N/A
 * Returns: N/A
 * Preconditions: function needs to be tested
 * Postconditions: function has been tested
 *************************************************************/
void testpopInt (void)
{
	IntDataStack *pTemp = NULL;
	printf ("Successful Push? %d\n", pushInt (&pTemp, 1));
	printf ("Popped Data? %d\n", popInt (&pTemp));
}

/*************************************************************
 * Function: testinfixConvertor ()
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 * Description: This function tests the infixConvertor function
 * Input parameters: N/A
 * Returns: N/A
 * Preconditions: function needs to be tested
 * Postconditions: function has been tested
 *************************************************************/
void testinfixConvertor (void)
{
	Bool success = false;
	char infixString[128] = "5+1+35-124", postfixString[128];
	success = infixConvertor (infixString, postfixString);
	printf ("Success? %d", success);
}

/*************************************************************
 * Function: testpostfixEvaluation ()
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 * Description: This function tests the postfixEvaluation function
 * Input parameters: N/A
 * Returns: N/A
 * Preconditions: function needs to be tested
 * Postconditions: function has been tested
 *************************************************************/
void testpostfixEvaluation (void)
{
	int success = 0;
	char infixString[128] = "5+1+35-124", postfixString[128];
	success = postfixEvaluation ("5 5 +");
	printf ("Success? %d", success);
}