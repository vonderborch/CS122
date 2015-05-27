/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 121, Fall 2011; Lab Section 3
 * Common Functions
 * Created: November 30th, 2011
 * Last Revised: February 21st, 2012
 * Description: This function consists of some common functions
 *
 * File Description: "common_functions.c" contains the function definitions
 *********************************************************************************************/
#include "common_functions.h"

/*************************************************************
 * Function: pause_clear ()
 * Date Created: November 30th, 2011
 * Date Last Modified: November 30th, 2011
 * Description: This function can pause and/or clear the screen
 * Input parameters: should the screen be paused, should the
 *						screen be cleared
 * Returns: N/A
 * Preconditions: the screen must be paused and/or cleared
 * Postconditions: the screen has been paused and/or cleared
 *************************************************************/
void pause_clear (Bool shouldPause, Bool shouldClear)
{
	// does the screen need to be paused
	if (shouldPause)
		system ("pause");
	// does the screen need to be cleared
	if (shouldClear)
		system ("cls");
}

/*************************************************************
 * Function: seedRandomGenerator ()
 * Date Created: November 30th, 2011
 * Date Last Modified: November 30th, 2011
 * Description: This function seeds the random number generator
 * Input parameters: whether the time should be assigned as the
 *						seed or not and the random seed
 * Returns: N/A
 * Preconditions: a random number is needed
 * Postconditions: a random number is returned
 *************************************************************/
void seedRandomGenerator (Bool assignTime, int randomSeed)
{
	// if the time should be assigned as the seed, assign it
	if (assignTime)
		srand ((unsigned) time (NULL));
	// otherwise assign the seed var as the seed
	else
		srand ((unsigned) randomSeed);
}

/*************************************************************
 * Function: getRandomNumber ()
 * Date Created: November 30th, 2011
 * Date Last Modified: February 21st, 2012
 * Description: This function returns a random int
 * Input parameters: the minimum number and max number for the
 *						random number's range
 * Returns: the random number
 * Preconditions: a random number is needed
 * Postconditions: a random number is returned
 *************************************************************/
int getRandomNumber (int minNum, int maxNum)
{
	int randomNum = 0, backupMax = maxNum;
	// increase the max num by one so it can actually be included in the range
	maxNum++;

	do
	{
		randomNum = rand () % maxNum + minNum;
	} while ((randomNum < minNum) || (randomNum > backupMax));
	// return a random number modded by the max number and added to
	//			by the min number
	return randomNum;
}

/*************************************************************
 * Function: getIntInputCheck ()
 * Date Created: November 13th, 2011
 * Date Last Modified: November 30th, 2011
 * Description: This function gets a "good" int input
 * Input parameters: the minimum good value, the maximum good value
 * Returns: the good int input
 * Preconditions: a "good" int input value is needed
 * Postconditions: a "good" int input value is returned
 *************************************************************/
int getIntInputCheck (int minGood, int maxGood)
{
	// declare variables
	int goodInputMain = 0, goodInputSub = 0, input = 0;
	// repeat while the desiered input is not achieved
	while (!goodInputMain)
	{
		// clear the buffer
		_flushall ();
		// get the input, assigned to the input variable.
		// assign the results of the scanf to a variable
		goodInputSub = scanf (" %d", &input);
		// if the scanf was successful...
		if (goodInputSub)
		{
			// check if the input falls in the range...
			if ((input >= minGood) && (input <= maxGood))
			{
				// break the input loop if it does
				goodInputMain = 1;
			}
		}
	}
	// return the "good" input
	return input;
}

/*************************************************************
 * Function: getDoubleInputCheck ()
 * Date Created: November 13th, 2011
 * Date Last Modified: November 30th, 2011
 * Description: This function gets a "good" double input
 * Input parameters: the minimum good value, the maximum good value
 * Returns: the good double input
 * Preconditions: a "good" double input value is needed
 * Postconditions: a "good" double input value is returned
 *************************************************************/
double getDoubleInputCheck (double minGood, double maxGood)
{
	// declare the variables
	int goodInputMain = 0, goodInputSub = 0;
	double input = 0.0;
	// repeat while the desiered input is not achieved
	while (!goodInputMain)
	{
		// clear the buffer
		_flushall ();
		// get the input, assigned to the input variable.
		// assign the results of the scanf to a variable
		goodInputSub = scanf (" %lf", &input);
		// check if the scanf was successful
		if (goodInputSub)
		{
			// check if the input falls within desiered range
			if ((input >= minGood) && (input <= maxGood))
			{
				// break the input loop
				goodInputMain = 1;
			}
		}
	}
	// return the "good" input
	return input;
}

void printMessage (char message[128], Bool shouldPause, Bool shouldClear)
{
	printf ("%s", message);
	pause_clear (shouldPause, shouldClear);
}