/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * PA4
 * Created: February 17th, 2011
 * Last Revised: February 22nd, 2012
 *
 * File Description: "main.c" contains the main function for the program.
 *********************************************************************************************/
#include "PA4.h"

/*************************************************************
 * Function: main ()
 * Created: February 17th, 2011
 * Last Revised: February 22nd, 2012
 * Description: This function controls the program.
 * Preconditions: the program needs to be run
 * Postconditions: the program has been run
 *************************************************************/
int main (void)
{
	// variables
	FILE *inFile = NULL;
	int sim_state = 0, option = 0, simNumber = 0;
	Bool isSaving = false;

	// main program loop
	while (sim_state >= 0)
	{
		// initial loading state
		if (sim_state == 0)
		{
			// load the resources file to check if it exists (and create one if need be).
			printf ("Loading resources file...");
			inFile = fopen ("resources.simr", "r");
			if (inFile == NULL)
			{
				printf ("Can't find the resources file, creating a new resources file...");
				inFile = fopen ("resources.simr", "w");
				fprintf (inFile, "0\n1");
				printf ("Resources file created...");
			}
			fclose (inFile);
			inFile = fopen ("resources.simr", "r");
			fscanf (inFile, "%d", &simNumber);
			fscanf (inFile, " %d", &isSaving);
			fclose (inFile);
			printf ("Resources file loaded!\n");
			// goto the main menu state
			sim_state = 1;
		}
		// show the main menu
		else
		{
			// get option from displayed menu
			option = display_menu (1, 0, ':', 1, 3, ";", "Grocery Store Simulation", "Main Menu",
				"Start New Simulation;Toggle Simulation Record Creation;Quit");
			// OPTIONS
			// run a new simulation
			if (option == 1)
			{
				// collect data from resources file
				inFile = fopen ("resources.simr", "r");
				fscanf (inFile, "%d", &simNumber);
				fscanf (inFile, " %d", &isSaving);
				simNumber++;
				fclose (inFile);
				inFile = fopen ("resources.simr", "w");
				fprintf (inFile, "%d\n%d", simNumber, isSaving);
				fclose (inFile);
				// run sim
				pa4_main (simNumber, isSaving);
			}
			// toggle simulation saving
			else if (option == 2)
			{
				// if it is currently saving, make it not
				if (isSaving)
				{
					printf ("No longer creating a record of simulations.\n");
					isSaving = false;
					inFile = fopen ("resources.simr", "w");
					fprintf (inFile, "%d\n%d", simNumber, isSaving);
					fclose (inFile);
				}
				// otherwise, make it save
				else
				{
					printf ("Now creating a record of simulations.\n");
					isSaving = true;
					inFile = fopen ("resources.simr", "w");
					fprintf (inFile, "%d\n%d", simNumber, isSaving);
					fclose (inFile);
				}
			}
			// end the program
			else
			{
				fclose (inFile);
				sim_state = -1;
			}
		}
	}

	return 0;
}