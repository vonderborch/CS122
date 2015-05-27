/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * PA1, Task 1
 * Created: January 22nd, 2012
 * Last Revised: January 24th, 2012
 *
 * File Description: "functions.c" contains the sub-functions for the program.
 *********************************************************************************************/

#include "task3.h"

/*************************************************************
 * Function: printMessage ()
 * Created: January 22nd, 2012
 * Last Revised: January 24th, 2012
 * Description: This function prints a message and
 *						can perform other functions
 * Input parameters: the message string, whether a new
 *								line is needed, whether to pause
 *								the screen, whether to clear the
 *								screen.
 * Returns: None
 * Preconditions: screen needs something done
 * Postconditions: screen has had something done
 *************************************************************/
void printMessage (char message[128], int newLine, int pause, int clear)
{
	// print the message
	printf ("%s", message);
	// add a new line
	if (newLine)
		printf ("\n");
	// pause the screen
	if (pause)
		system ("pause");
	// clear the screen
	if (clear)
		system ("cls");
}

/*************************************************************
 * Function: wordConvert ()
 * Created: January 22nd, 2012
 * Last Revised: January 24th, 2012
 * Description: This function converts a word
 * Input parameters: None
 * Returns: None
 * Preconditions: a word needs to be converted
 * Postconditions: a word has been converted
 *************************************************************/
void wordConvert (void)
{
	// variables
	char word[128];
	int isEncrypt = 0, encryptValue = 0,
		wordLength = 0, i = 0, tempKey = 0, newValue = 0;

	// ask for word to be encyrpted or decrypted
	printMessage ("Word to Encrypt or Decrypt? ", 0, 0, 0);
	scanf (" %s", &word);

	// ask if word is to be encyrpted or decrypted
	printMessage ("Encrypt (0) or Decrypt (1)?", 0, 0, 0);
	scanf (" %d", &isEncrypt);

	// ask for the key
	printMessage ("Encrypt Key?", 0, 0, 0);
	scanf (" %d", &encryptValue);

	// make key negative if decrypting
	if (isEncrypt == 1)
	{
		encryptValue = -encryptValue;
	}

	// get the length of the string
	wordLength = strlen (word);

	// cycle through each character, making it uppercase
	for (i = 0; i < wordLength; i++)
	{
		word[i] = toupper(word[i]);
	}

	// cycle through each character, changing it by the encrypt value
	for (i = 0; i < wordLength; i++)
	{
		// set up temp value
		tempKey = encryptValue;
		// set up the new value
		newValue = (int)word[i] + tempKey;
		// check if changing the char will push it over an alphabet boundary
		// A
		if (newValue < 65)
		{
			// set the change key to the value over - 65 + 1 (conversion to Z for char)
			tempKey = (newValue - 65) + 1;
			word[i] = 'Z';
		}
		// Z
		if (newValue > 90)
		{
			// set the change key to the value over - 90 - 1 (conversion to A for char)
			tempKey = (newValue - 90) - 1;
			word[i] = 'A';
		}
		// convert character
		word[i] = (char)((int)word[i] + tempKey);
	}

	// print that the new word
	printMessage (word, 1, 0, 0);
}