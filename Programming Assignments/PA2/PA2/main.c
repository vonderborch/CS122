/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * PA1, Task 1
 * Created: January 27th, 2012
 * Last Revised: February 2nd, 2012
 *
 * File Description: "main.c" contains the main for the program.
 *********************************************************************************************/

#include "PA2.h"

/*************************************************************
 * Function: main ()
 * Created: January 27th, 2012
 * Last Revised: February 2nd, 2012
 * Description: This function controls the program
 * Input parameters: None
 * Returns: None
 * Preconditions: the program needs to be run
 * Postconditions: the program has been run
 *************************************************************/
int main (void)
{
	// variables
	char programTitle[] = "Digital Music Manager";
	Node *pSongs = NULL;
	int prog_state = 0, sub_state = 0, option = 0;
	Bool success = false;
	FILE *ioFile = NULL;

	while (prog_state >= 0)
	{
		//// LOADING ////
		if (prog_state == 0)
		{
			// open the music file
			ioFile = fopen ("music.dmm", "r+");
			prog_state = 1;
		}

		//// MAIN MENU ////
		else if (prog_state == 1)
		{
			// display menu and get selected option
			option = display_menu (2, 2, ':', 1, 9, ";", programTitle, "Main Menu",
				"Display Songs;Rate Songs;Sort Songs;Add Song;Edit Song;Delete Song;Load Songs;Store Songs;Exit Digital Music Manager");
			// Display Songs
			if (option == 1)
			{
				displaySongs (pSongs);
			}
			// Rate Songs
			else if (option == 2)
			{
				editSong (1, &pSongs);
			}
			// Sort Songs
			else if (option == 3)
			{
				sortSongs (&pSongs, display_menu (2, 2, ':', 1, 3, ";", programTitle, "Choose an Insert Order...",
					"Insert by Song Title;Insert by Genre;Insert by Rating"));
			}
			// Add Song
			else if (option == 4)
			{
				success = addSong (&pSongs);
				if (!success)
				{
					printf ("Failed to create song!\n");
				}
				else
				{
					sortSongs (&pSongs, display_menu (2, 2, ':', 1, 3, ";", programTitle, "Choose an Insert Order...",
						"Insert by Song Title;Insert by Genre;Insert by Rating"));
				}
			}
			// Edit Song
			else if (option == 5)
			{
				editSong (0, &pSongs);
			}
			// Delete Song
			else if (option == 6)
			{
				deleteSong (&pSongs);
			}
			// Load Songs
			else if (option == 7)
			{
				loadSongs (&pSongs, ioFile);
			}
			// Store Songs
			else if (option == 8)
			{
				storeSongs (pSongs, ioFile);
			}
			// Exit program
			else if (option == 9)
			{
				fclose (ioFile);
				prog_state = -1;
			}
		}
	}
	return 0;
}