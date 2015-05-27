/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 121, Fall 2011; Lab Section 3
 * Standard Menu System
 * Created: September 28th, 2011
 * Last Revised: January 25th, 2012
 * Description: This function set allows a menu to be generated and a valid answer
 *							to be selected and returned.
 *
 * File Changelog:
 *					January 28th, 2012: Removed old menu system functions, cleaned up
 *									file, and finished new function.
 *					January 25th, 2012: Created new menu system function to replace
 *									old ones.
 *					November 30th, 2011: Cleanup of selector menu and standardization
 *									for both menu types.
 *					November 12th and 13th, 2011: Addition of a selector menu (uses arrow keys)
 *									as an alternate to the regular menu (letter/number input) and support
 *									functions.
 *					October 5th and 10th, 2011: Improvements to initial menu system for
 *									error checking.
 *					September 28th and 29th, 2011: Creation of initial menu system and support
 *									functions.
 *
 * File Description: "menu_system.h" contains the various includes and function
 *									prototypes which control the menu_system.c file functions.
 *********************************************************************************************/

#include "menu_system.h"

/*************************************************************
 * Function: display_menu ()
 * Date Created: January 25th, 2012
 * Date Last Modified: January 85th, 2012
 * Changelog:
 *					January 28th, 2012: Finished creation of function.
 *					January 25th, 2012: Created function. Merged old menu display functions.
 * Description: This function displays a menu, determined by the passed information.
 * Input parameters:
 *							inputMode: 0 = number/char input (used with itemPre for numbers
 *												vs. letters), 1 = arrows, 2 = both.
 *							itemPreType: 0 = use nothing, 1 = use lowercase letters,
 *												2 = use uppercase letters
 *							itemPreChar: character to seperate the pre and the item.
 *							minItem: Lowest possible option.
 *							numItems: Number (start at 1) of items in the menu. Doubles as highest
 *												possible option.
 *							itemDelim: delim char(s) between menu items.
 *							menuTitle: A string containing the title of the program. No need for
 *												included new line.
 *							programTitle: A string containing the title of the menu. No need for
 *												included new line.
 *							menuItems: A string containing all menu items (printed as one,
 *												include new lines aside from last one). Max of 64
 *												items in a single menu. Each item must be a max of 64
 *												chars long.
 * Special Notes: Don't use non arrow input if there are more than 26 items.
 * Returns: Item selected as an int
 * Preconditions: Menu needs to be displayed for an option to be gotten
 * Postconditions: Returns the menu option selected.
 *************************************************************/
int display_menu (int inputMode, int itemPreType, char itemPreChar, int minItem, int numItems,
				  char itemDelim[], char programTitle[], char menuTitle[], char menuItems[])
{
	///////////////////////////////
	////////// VARIABLES //////////
	///////////////////////////////
	int option = minItem, i = 0, j = 0, isSelected = 0,
		inputCycle = 1, specialKey = 0, optionCheck = 0;
	char backupMenu[4096], menu[64][64], *tempItem, char_item = '\0';
	KeyInput keysSelected;

	////////////////////////////////
	////////// BUILD MENU //////////
	////////////////////////////////
	strcpy (backupMenu, menuItems);
	tempItem = strtok (backupMenu, itemDelim);
	strcpy (menu[0], tempItem);
	for (i = 1; i < numItems; i++)
	{
		tempItem = strtok (NULL, itemDelim);
		strcpy (menu[i], tempItem);
	}

	////////////////////////////////
	////////// MENU LOGIC //////////
	////////////////////////////////
	do
	{
		//// DISPLAY MENU ////
		// Display Program and Menu Titles
		printf ("%s\n",programTitle);
		printf ("%s\n\n",menuTitle);
		// Display Items
		for (i = 1; i <= numItems; i++)
		{
			// Print selector icon
			// option is selected
			if (option == i)
			{
				printf ("> ");
			}
			// option is not selected
			else
			{
				printf ("  ");
			}

			// print number or characters if necessary
			if (inputMode == 0 || inputMode == 2)
			{
				// if nothing, print nothing
				if (itemPreType == 1 || itemPreType == 2)
				{
					j = i;
					while (j > 0)
					{
						char_item = char_reverse_convert (j, itemPreType - 2);
						printf ("%c", char_item);
						j -= 26;
					}
				}
				// print the char after the id but before the item
				printf ("%c ", itemPreChar);
			}
			// print item string
			printf ("%s\n", menu[i - 1]);
		}

		//// GET INPUT ////
		do
		{
			// sleep the program for a bit to help with input detection
			Sleep (200);
			// get input
			keysSelected = getKeySelected ();
			// check keys if one was pressed
			if (keysSelected.key != '\0')
			{
				// check if a special key was pressed
				if (keysSelected.key == '~')
				{
					specialKey = 1;
				}

				// if a special key was pressed
				if (specialKey == 1)
				{
					// check arrows if allowed
					if ((inputMode == 1) || (inputMode == 2))
					{
						// up and left
						if ((keysSelected.specialKey == 'W') || (keysSelected.specialKey == 'A'))
						{
							option--;
						}
						// down and right
						else if ((keysSelected.specialKey == 'S') || (keysSelected.specialKey == 'D'))
						{
							option++;
						}
					}
					// check enter
					if (keysSelected.specialKey == 'E')
					{
						isSelected = 1;
					}
				}
				// otherwise
				else
				{
					// check if allowed to do letter input
					if ((inputMode == 0) || (inputMode == 2))
					{
						// assign the key selected to a check variable and check if it is
						//			a valid option
						optionCheck = char_convert(keysSelected.key);
						if ((optionCheck >= minItem) && (optionCheck <= numItems))
						{
							// if it is, assign the option to the selected key
							option = optionCheck;
						}
					}
				}
				// end the input cycle
				inputCycle = 0;
			}
		} while (inputCycle);

		// OPTION VALIDITY CHECK
		if (option < minItem)
		{
			option = numItems;
		}
		else if (option > numItems)
		{
			option = minItem;
		}

		// RESET INPUT CYCLE
		inputCycle = 1;
		specialKey = 0;

		// CLEAR SCREEN
		system ("cls");
	} while (!isSelected);

	_flushall();
	// return the option selected
	return option;
}

/*************************************************************
 * Function: getKeySelected ()
 * Date Created: September 28th, 2011
 * Date Last Modified: January 28th, 2012
 * Description: This function gets the current
 *						pressed key. Special input keys
 *						have priority over regular input keys..
 * Input parameters: N/A
 * Returns: A value for the key
 * Preconditions: A key input is needed
 * Postconditions: The key input is gotten
 *************************************************************/
KeyInput getKeySelected (void)
{
	int i = 0;
	KeyInput key = {'\0', '\0'};
	/* SPECIALKEY KEYCODES
	 * Key = ~
	 Special Key =
	 * Up Arrow: W
	 * Left Arrow: A
	 * Down Arrow: S
	 * Right Arrow: D
	 * Enter: E
	*/

	//// LETTERS
	for (i = 1; i <= 26; i++)
	{
		 if (GetAsyncKeyState ((char)(i + 64)))
		 {
			 key.key = (char)(i + 64);
		 }
	}

	//// SPECIAL KEYS
	// up arrow selected
	if (GetAsyncKeyState (VK_UP))
	{
		key.key = '~';
		key.specialKey = 'W';
	}
	// left arrow selected
	else if (GetAsyncKeyState (VK_LEFT))
	{
		key.key = '~';
		key.specialKey = 'A';
	}
	// right arrow selected

	else if (GetAsyncKeyState (VK_RIGHT))
	{
		key.key = '~';
		key.specialKey = 'D';
	}
	// down arrow selected
	else if (GetAsyncKeyState (VK_DOWN))
	{
		key.key = '~';
		key.specialKey = 'S';
	}
	// enter selected
	else if (GetAsyncKeyState (VK_RETURN) & 0x8000)
	{
		key.key = '~';
		key.specialKey = 'E';
	}

	// return key
	return key;
}

/*************************************************************
 * Function: char_convert ()
 * Date Created: September 28th, 2011
 * Date Last Modified: October 10th, 2011
 * Description: This function converts a char value to a
 *						int version of itself (adjusted so A = 0 and
 *						lower + uppercases have the same value).
 * Input parameters: value - the char value to adjust
 * Returns: The adjusted char value
 * Preconditions: A char value is needed to be adjusted.
 * Postconditions: The char value has been adjusted.
 *************************************************************/
int char_convert (char value)
{
	// assign the char value to a int version and reduce it's value by 64
	int int_value = (int)value - 64;
	// if the value is greater than 32, reduce it by 32
	if (int_value > 32)
	{
		int_value -= 32;
	}
	// return the value
	return int_value;
}

/*************************************************************
 * Function: char_reverse_convert ()
 * Date Created: November 12th, 2011
 * Date Last Modified: November 13th, 2011
 * Description: This function converts a passed char
 *						into a lower or upper-cased char.
 * Input parameters: value - the value to adjust.
 *								is_upper - Should it be uppercase?
 * Returns: The adjusted char value
 * Preconditions: A char value is needed to be adjusted.
 * Postconditions: The char value has been adjusted.
 *************************************************************/
char char_reverse_convert (int value, int is_upper)
{
	// create a temporary char variable
	char char_value = '\0';
	// add 64 to the passed value
	int int_value = value + 64;
	// if it is supposed to be lowercase, add another 32 to it
	if (!is_upper)
	{
		int_value += 32;
	}
	// convert it to a char and return it
	char_value = (char)int_value;
	return char_value;
}