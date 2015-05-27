/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * PA1, Task 1
 * Created: January 22nd, 2012
 * Last Revised: January 24th, 2012
 *
 * File Description: "functions.c" contains the sub-functions for the program.
 *********************************************************************************************/

#include "task2.h"

/*************************************************************
 * Function: checkPalindrome ()
 * Created: January 22nd, 2012
 * Last Revised: January 24th, 2012
 * Description: This checks if a inputted word is a
 *							palindrome or not
 * Input parameters: None
 * Returns: None
 * Preconditions: a palindrome needs to be checked
 * Postconditions: a palindrome has been checked
 *************************************************************/
void checkPalindrome (void)
{
	// variables
	int i = 0, str_length = 0, is_palindrome = 0;
	char input_word[1024] = "",
		input_word2[1024] = "",
		input_backup[1024];

	// ask and get the word, clearing the buffer just in case
	printf ("Word/Phrase for Palindrome Checking? ");
	_flushall ();
	gets (input_word);

	// make a backup copy of the inputted word
	strcpy (input_backup, input_word);

	// get string length
	for (str_length = 0; input_word[str_length] != '\0'; str_length++);

	// remove whitespace
	remove_punc (str_length, input_word, input_word2);

	// recalculate string length
	for (str_length = 0; input_word2[str_length] != '\0'; str_length++);

	// determine if palindrome
	is_palindrome = determine_palindrome (0, str_length-1, input_word2);

	// print/pause result, then exit task
	if (is_palindrome)
		printf ("The word/sentance inputted, %s, is a palindrome!\n\n", input_backup);
	else
		printf ("The word/sentance inputted, %s, is not a palindrome!\n\n", input_backup);
	// pause and clear the screen
	pause_clear (1, 1);
}

/*************************************************************
 * Function: remove_punc ()
 * Created: January 22nd, 2012
 * Last Revised: January 24th, 2012
 * Description: This function removes punctuation
 * Input parameters: None
 * Returns: None
 * Preconditions: punctuation needs to be removed
 * Postconditions: punctuation has been removed
 *************************************************************/
void remove_punc (int str_length, char *source, char *destination)
{
	// set up variables
	char temp[1024] = "";
	int i = 0, counter = 0;

	// cycle through all letter making sure that they are valid
	while (source[i] != '\0')
	{
		if (isalpha(source[i]))
		{
			if (!ispunct (source[i]))
			{
				if (islower(source[i]))
				{
					source[i] = toupper(source[i]);
				}
				temp[counter] = source[i];
				counter++;
			}
		}
		i++;
	}
	// copy the modified string back into the passed
	strcpy(destination, temp);
}

/*************************************************************
 * Function: determine_palindrome ()
 * Created: January 22nd, 2012
 * Last Revised: January 24th, 2012
 * Description: This function determines whether the
 *						word is a palindrome
 * Input parameters: None
 * Returns: None
 * Preconditions: a word must be checked
 * Postconditions: a word has been checked
 *************************************************************/
int determine_palindrome (int left, int right, char string[])
{
	// set palindrome to being false
	int is_palindrome = 0;
	// cycle through each letter pair recursively checking to see if they match
	if (string[left] == string[right])
	{
		// set palindrome to being true
		is_palindrome = 1;
		// increment the variables
		left++;
		right--;
		// if we are less than halfway through, check the next pair
		if (left < right)
		{
			is_palindrome = determine_palindrome (left, right, string);
		}
	}
	// return the palindrome condition
	return is_palindrome;
}

/*************************************************************
 * Function: pause_clear ()
 * Created: January 22nd, 2012
 * Last Revised: January 24th, 2012
 * Description: This function pauses or clears the interface
 * Input parameters: None
 * Returns: None
 * Preconditions: the interface must be paused or cleared
 * Postconditions: the interface has been paused or cleared
 *************************************************************/
void pause_clear (int pause, int clear)
{
	// pause the screen
	if (pause)
		system ("pause");
	// clear the screen
	if (clear)
		system ("cls");
}