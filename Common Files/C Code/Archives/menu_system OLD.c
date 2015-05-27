/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 121, Fall 2011; Lab Section 3
 * Standard Menu System
 * Created: October 5th, 2011
 * Last Revised: November 30th, 2011
 * Description: This function set allows a menu to be generated and a valid answer
 *							to be selected and returned.
 *
 * File Description: "menu_system.h" contains the various includes and function
 *									prototypes which control the menu_system.c file functions.
 *********************************************************************************************/

#include "menu_system.h"

/*************************************************************
 * Function: display_standard_menu ()
 * Date Created: September 28th, 2011
 * Date Last Modified: November 21st, 2011
 * Changelog:
 *					November 21st, 2011: Replaced "flushall" with "_flushall"
 *					November 13th, 2011: Cleaned up some code. Modified menu_items to be
 *														more "dynamic."
 *					October 10th, 2011: Adjusted input detection to check for errors (invalid
 *														datatype). Modified to accept option for using
 *														character input rather than menu. Modified
 *														input parameter description for descriptiveness.
 *					October 5th, 2011: Added comments to function.
 *					September 29th, 2011: Changed function to work for any menu inputed.
 *					September 28th, 2011: Function created to generate main menu.
 * Description: This function displays a menu, determined by a string
 *					passed into it, and allows the user to select a
 *					valid item (error-checks for invalid item).
 * Input parameters:
 *							menu_type: Use 0 for number menu, 1 for letter menu.
 *							min_items: Lowest option. If menu_type is Char-based, use
 *													'lowest' uppercase character used in Menu (i.e. A).
 *													Will automatically calculate lowercase version.
 *													Pass as an integer.
 *							num_items: Maximum option. If menu_type is Char-based, use
 *													'highest' uppercase character used in Menu (i.e. Z).
 *													Will automatically calculate lowercase version.
 *													Pass as an integer.
 *							menu_title: A string containing the title of the menu. No need for
 *													included new line.
 *							menu_items: A string containing all menu items (printed as one,
 *													include new lines aside from last one).
 * Returns: Item selected as an int
 * Preconditions: Menu needs to be displayed for an option to be gotten
 * Postconditions: Returns the menu option selected.
 *************************************************************/
int display_standard_menu (int menu_type, int min_items, int num_items, char menu_title[], char menu_items[][128])
{
	// set current option to 0
	int option = 0, error_check = 0, item = 0;
	char char_option = '\0', char_item = '\0';

	// repeat while option is invalid
	do
	{
		// DISPLAY MENU
		// display menu title
		printf ("%s\n\n",menu_title);
		// display menu items
		for (item = 1; item <= num_items; item++)
		{
			// PRINT ITEM NUMBER/LETTER
			if (!menu_type)
			{
				// print number
				printf ("%d", item);
			}
			else
			{
				// convert item# to a capitol char (starting at A) and print
				char_item = char_reverse_convert (item, 1);
				printf ("%c", char_item);
			}
			// print item number/letter and string seperator
			printf (". ");
			// DISPLAY ITEM STRING
			printf ("%s\n", menu_items[item - 1]);
		}
		printf ("\n");

		// GET OPTION SELECTED
		// If the menu is integer based...
		if (!menu_type)
		{
			// get user selection input and assign the results of the scanf to a variable to error check
			error_check = scanf (" %d", &option);
		}
		// if the menu is char-based...
		else
		{
			// get user selection input and assign the results of the scanf to a variable to error check
			error_check = scanf (" %c", &char_option);
		}

		// CHECK FOR USER INPUT ERROR / CONVERT CHAR IF CHAR MENU
		// check if there was an error
		if (!error_check)
		{
			// if it did, assign option var to the lowest item -1 (always invalid).
			option = min_items - 1;
		}
		// if there wasn't and the menu type is a char, convert the char value
		else if (menu_type)
		{
			option = char_convert (char_option);
		}

		// CLEAR THE BUFFER
		_flushall();

		// CLEAR SCREEN
		system ("cls");
		// DETERMINE WHETHER THE OPTION SELECTED WAS VALID
	} while (!is_valid_item (option, num_items, min_items));

	// RETURN THE SELECTED OPTION
	return option;
}

/*************************************************************
 * Function: display_selector_menu ()
 * Date Created: November 13th, 2011
 * Date Last Modified: November 27th, 2011
 * Changelog:
 *					November 30th, 2011: Commented menu
 *					November 27th, 2011: Key input uses the KeyInput
 *							struct rather than being number-based.
 *					November 21st, 2011: Modified function to deal with
 *							key-press buffer issues.
 *					November 13th, 2011: Created function.
 * Description: This function displays a menu, determined by a string
 *					passed into it, and allows the user to select a
 *					valid item (error-checks for invalid item) using both
 *					both WASD and the arrow keys and enter to select.
 * Input parameters:
 *							min_items: Lowest option. If menu_type is Char-based, use
 *													'lowest' uppercase character used in Menu (i.e. A).
 *													Will automatically calculate lowercase version.
 *													Pass as an integer.
 *							num_items: Maximum option. If menu_type is Char-based, use
 *													'highest' uppercase character used in Menu (i.e. Z).
 *													Will automatically calculate lowercase version.
 *													Pass as an integer.
 *							menu_title: A string containing the title of the menu. No need for
 *													included new line.
 *							menu_items: A string containing all menu items (printed as one,
 *													include new lines aside from last one).
 * Returns: Item selected as an int
 * Preconditions: Menu needs to be displayed for an option to be gotten
 * Postconditions: Returns the menu option selected.
 *************************************************************/
int display_selector_menu (int min_items, int num_items, char menu_title[], char menu_items[][128])
{
	// set current option to 0
	int option = min_items, input_cycle = 1, item = 0, is_selected = 0, input = 0, key = 0;
	char char_option = '\0', inputKey = '\0';
	KeyInput inputKeys = {'\0', '\0'};

	// repeat while option is invalid
	do
	{
		// DISPLAY MENU
		// display menu title
		printf ("%s\n\n",menu_title);
		// display menu items
		for (item = 1; item <= num_items; item++)
		{
			// print the selector icon if selected item
			if (option == item)
			{
				printf ("> ");
			}
			// else, print whitespace
			else
			{
				printf ("  ");
			}
			// display item string
			printf ("%s\n", menu_items[item - 1]);
		}
		printf ("\n");

		// GET USER INPUT
		// get input
		do
		{
			Sleep (200);
			inputKeys = getKeySelected ();
			//input = getKeySelected ();
			if (inputKeys.key != '\0')
			{
				input_cycle = 0;
				inputKey = inputKeys.key;
				if (inputKeys.key == '~')
				{
					inputKey = inputKeys.specialKey;
				}

				if ((inputKey == 'W') || (inputKey == 'A'))
				{
					option--;
					if (option < min_items)
					{
						option = num_items;
					}
				}
				else if ((inputKey == 'S') || (inputKey == 'D'))
				{
					option++;
					if (option > num_items)
					{
						option = min_items;
					}
				}
				else if (inputKey == 'E')
				{
					is_selected = 1;
				}
			}
		} while (input_cycle);

		// OPTION VALIDITY CHECK
		if (option < min_items)
		{
			option = num_items;
		}
		else if (option > num_items)
		{
			option = min_items;
		}

		// CLEAR THE BUFFER
		input_cycle = 1;

		// CLEAR SCREEN
		system ("cls");
		// DETERMINE WHETHER THE OPTION SELECTED WAS VALID
	} while (!is_selected);

	// RETURN THE SELECTED OPTION
	return option;
}

/*************************************************************
 * Function: getKeySelected ()
 * Date Created: September 28th, 2011
 * Date Last Modified: November 27th, 2011
 * Description: This function gets the current
 *						pressed key
 * Input parameters: N/A
 * Returns: A value for the key
 * Preconditions: A key input is needed
 * Postconditions: The key input is gotten
 *************************************************************/
KeyInput getKeySelected (void)
{
	KeyInput key = {'\0', '\0'};
	/* SPECIALKEY KEYCODES
	 * Up Arrow: W
	 * Left Arrow: A
	 * Right Arrow: D
	 * Down Arrow: S
	 * Enter: E
	*/

	// up arrow selected
	if (GetAsyncKeyState (VK_UP))
	{
		key.key = '~';
		key.specialKey = 'W';
	}
	// W selected
	else if (GetAsyncKeyState ('W'))
	{
		key.key = 'W';
	}
	// left arrow selected
	else if (GetAsyncKeyState (VK_LEFT))
	{
		key.key = '~';
		key.specialKey = 'A';
	}
	// A selected
	else if (GetAsyncKeyState ('A'))
	{
		key.key = 'A';
	}
	// right arrow selected
	else if (GetAsyncKeyState (VK_RIGHT))
	{
		key.key = '~';
		key.specialKey = 'D';
	}
	// D selected
	else if (GetAsyncKeyState ('D'))
	{
		key.key = 'D';
	}
	// down arrow selected
	else if (GetAsyncKeyState (VK_DOWN))
	{
		key.key = '~';
		key.specialKey = 'S';
	}
	// S selected
	else if (GetAsyncKeyState ('S'))
	{
		key.key = 'S';
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
	int int_value = (int)value - 64;
	if (int_value > 32)
	{
		int_value -= 32;
	}
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
	char char_value = '\0';
	int int_value = (int)value + 64;
	if (!is_upper)
	{
		int_value += 32;
	}
	char_value = (char)int_value;
	return char_value;
}

/*************************************************************
 * Function: is_valid_item ()
 * Date Created: September 28th, 2011
 * Date Last Modified: October 10th, 2011
 * Description: This function determines whether the selected
 *					menu choice is a valid option or not.
 * Input parameters: option - selected option, num_items -
 *						total number of menu options,
 *						min_items - lowest selectable option.
 * Returns: Whether the option selected is valid or not.
 * Preconditions: Option needs to be checked if valid.
 * Postconditions: Validity of option returned.
 *************************************************************/
int is_valid_item (int option, int num_items, int min_items)
{
	// set validity to no
	int valid = 0;
	// if option falls inside the min/max items, validity is yes
	if ((option >= min_items) && (option <= num_items))
	{
		valid = 1;
	}
	// if option falls outside the min/max items, validity is no
	//			and the user is informed of a input-error.
	else
	{
		printf ("Please enter valid input.\n");
	}
	// return validity
	return valid;
}