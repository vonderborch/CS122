/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * PA3
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 *
 * File Description: "main.c" contains the main for the program.
 *********************************************************************************************/
#include "pa3.h"
#include "testPA.h"

/*************************************************************
 * Function: main ()
 * Created: February 6th, 2012
 * Last Revised: February 10th, 2012
 * Description: This function controls the program
 * Input parameters: None
 * Returns: None
 * Preconditions: the program needs to be run
 * Postconditions: the program has been run
 *************************************************************/
int main (void)
{
	// variables
	int prog_state = 0, option = 0;
	Bool isSaving = true;

	// main program loop
	while (prog_state >= 0)
	{
		// display the menu
		option = display_menu (1, 0, ':', 1, 3, ";", "PA3 - Evaluation of Infix Expressions Using Stacks",
			"Main Menu", "Convert New Expression;Toggle Expression Saving;Quit");
		// menu options
		if (option == 1)
		{
			// clear the buffer
			rewind (stdin);
			// convert new expression
			pa3_main (isSaving);
		}
		// toggle expression saving
		else if (option == 2)
		{
			// if the program is saving expressions, make it stop and say so
			if (isSaving)
			{
				isSaving = false;
				printf ("Expression Saving is Off.\n");
			}
			// if the program is not saving expressions, make it and say so
			else
			{
				isSaving = true;
				printf ("Expression Saving is On.\n");
			}
		}
		// exit program
		else
		{
			prog_state = -1;
		}
	}

	return 0;
}