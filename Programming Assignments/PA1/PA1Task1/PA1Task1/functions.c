/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * PA1, Task 1
 * Created: January 22nd, 2012
 * Last Revised: January 24th, 2012
 *
 * File Description: "functions.c" contains the sub-functions for the program.
 *********************************************************************************************/

#include "task1.h"

/*************************************************************
 * Function: printStrings ()
 * Created: January 22nd, 2012
 * Last Revised: January 24th, 2012
 * Description: This prints out the array of strings
 * Input parameters: the pointer array to the string array
 *									and the number of words.
 * Returns: None
 * Preconditions: the strings need to be printed
 * Postconditions: the strings have been printed
 *************************************************************/
void printStrings (char *pointers[], int wordCount)
{
	// setup counter
	int i = 0;
	// cycle through each word, printing it
	for (i = 0; i < wordCount; i++)
	{
		printf ("%s\n", pointers[i]);
	}
}

/*************************************************************
 * Function: sortStrings ()
 * Created: January 22nd, 2012
 * Last Revised: January 24th, 2012
 * Description: This function sorts the strings
 * Input parameters: the pointer array to the string array
 *									and the number of words.
 * Returns: Indirectly the sorted array
 * Preconditions: the strings need to be sorted
 * Postconditions: the strigns have been sorted
 *************************************************************/
void sortStrings (char **pointers[], int wordCount)
{
	// variables
	int indexU = wordCount, indexC = 1, compareValue = 0, i = 0,
		unSorted = wordCount * wordCount;
	char *tempPointer;

	// print that the strings are being sorted
	printf ("\nSorting Strings..");

	// allocate memory to the temp pointer
	tempPointer = (char *) malloc (64 * sizeof (char));

	// cycle through the strings, sorting them until none are left to be sorted
	while (unSorted > 0)
	{
		for (indexC = 1; indexC < indexU; indexC++)
		{
			// print that a sorting cycle is occuring
			printf (".");
			// set i to the string before this one
			i = indexC - 1;
			// compare the strings
			compareValue = strcmp (&*pointers[indexC], &*pointers[i]);
			// if the compared value is less than 0, flip the strings
			if (compareValue < 0)
			{
				tempPointer = pointers[indexC];
				pointers[indexC] = pointers[i];
				pointers[i] = tempPointer;
			}
			// otherwise, reduce the number of unsorted by 1
			else
			{
				unSorted--;
			}
		}
	}

	// print that sorting is complete
	printf ("Strings Sorted!\n\n");
}