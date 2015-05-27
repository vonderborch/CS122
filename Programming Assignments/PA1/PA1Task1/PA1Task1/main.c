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

#include "task1.h"

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
	int wordCount = 7, i = 0;
	// string list and pointer to the list
	char stringList[][64] = {"Hi", "Bye", "Good Day", "My name is...", "Civilization", "Snow", "School"};
	char *stringPointers[64];

	// Set pointers to the strings
	for (i = 0; i < wordCount; i++)
	{
		stringPointers[i] = (char *) malloc (strlen (stringList[i]) + 1);
		//stringPointers[i] = (char *) malloc (64 * sizeof (char));
		stringPointers[i] = stringList[i];
	}

	// Print the non-ordered strings
	printStrings (stringPointers, wordCount);

	// sort the strings
	sortStrings (&stringPointers, wordCount);

	// print the ordered strings
	printStrings (stringPointers, wordCount);

	return 0;
}