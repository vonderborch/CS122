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

#include "task3.h"

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
	int isConverting = 1;

	// cycle while converting
	while (isConverting == 1)
	{
		// convert word
		wordConvert ();
		// ask if user wants to convert a new word
		printMessage ("Perform Encryption/Decryption Again (1 = Yes, 0 = No)?", 1, 0, 0);
		scanf ("%d", &isConverting);
		// clear the screen
		printMessage ("", 0, 0, 1);
	}

	return 0;
}