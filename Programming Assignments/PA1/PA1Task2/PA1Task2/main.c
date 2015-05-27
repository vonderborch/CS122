/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * PA1, Task 1
 * Created: January 22nd, 2012
 * Last Revised: January 24th, 2012
 *
 * File Description: "main.c" contains the main function through which the program
 *											is run.
 *********************************************************************************************/

#include "task2.h"

/*************************************************************
 * Function: main ()
 * Created: January 22nd, 2012
 * Last Revised: January 24th, 2012
 * Description: This function controls the program
 * Input parameters: None
 * Returns: None
 * Preconditions: the program needs to be run
 * Postconditions: the program has been run
 *************************************************************/
int main (void)
{
	// variables
	int isChecking = 1;

	// repeat the palindrome check while the user wants to
	while (isChecking)
	{
		// check for palindrome
		checkPalindrome ();
		// ask if a new one needs to be checked
		printf ("Check a New Phrase (1 = Yes, 0 = No)? ");
		scanf (" %d", &isChecking);
	}

	return 0;
}