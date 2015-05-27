/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * PA4
 * Created: February 17th, 2011
 * Last Revised: February 22nd, 2012
 *
 * File Description: "functions.c" contains the basic functions.
 *********************************************************************************************/
#include "PA4.h"

/*************************************************************
 * Function: pa4_main ()
 * Created: February 17th, 2011
 * Last Revised: February 22nd, 2012
 * Description: This function controls the simulation.
 * Preconditions: the simulation needs to be run
 * Postconditions: the simulation has been run
 *************************************************************/
void pa4_main (int simulation_number, Bool isSaving)
{
	// variable declaration
	FILE *outFile = NULL;
	char simulationFile[64], itoaBuffer[4];
	CustomerData tempData;
	Queue normalLane, expressLane;
	int sim_state = 0, ticks = 0, maxTicks = 0, custNum = 0,
		nextNormal = 0, nextExpress = 0,
		totalNormal = 0, totalExpress = 0, totalDifference = 0;
	KeyInput keys;

	// print simulation control keys for user to know
	printf ("Press [Spacebar] at any point to end the simulation.\n");
	printf ("Press [P] at any point to pause the simulation.\n\n");
	// main simulation control loop
	while (sim_state >= 0)
	{
		// initial setup
		if (sim_state == 0)
		{
			// create the simulation save file if supposed to
			if (isSaving)
			{
				strcpy (simulationFile, "simulation");
				strcat (simulationFile, itoa (simulation_number, itoaBuffer, 10));
				strcat (simulationFile, ".txt");
				outFile = fopen (simulationFile, "w");
			}
			// print welcome screen
			printf ("******** Grocery Store Simulator ********\nSimulation #%d\n\n", simulation_number);
			if (isSaving)
				fprintf (outFile, "******** Grocery Store Simulator ********\nSimulation #%d\n\n", simulation_number);
			// ask how long simulation should last
			printf ("How long should the Simulation last (-1 = till manually ended)? ");
			maxTicks = getIntInputCheck (-1, 99999999999999999);
			// initialize the lanes
			initializeQueue (&normalLane);
			initializeQueue (&expressLane);
			// set tick count to 0
			ticks = 0;
			// seed the random number generator
			seedRandomGenerator (true, 0);
			// get and print the first arrival times
			nextNormal = getArrivalTime (false);
			nextExpress = getArrivalTime (true);
			printf ("First Normal Line Arrival: %d minute(s).\nFirst Express Line Arrival: %d minute(s).\n", nextNormal, nextExpress);
			if (isSaving)
				fprintf (outFile, "First Normal Line Arrival: %d minute(s).\nFirst Express Line Arrival: %d minute(s).\n", nextNormal, nextExpress);
			sim_state = 1;
		}
		// normal simulation
		else if (sim_state == 1)
		{
			// as long as we having meet the final tick
			if (ticks != maxTicks)
			{
				// tick increment/decrement
				ticks++;
				nextNormal--;
				nextExpress--;
				// NEW CUSTOMER ARRIVAL
				// check if a new normal customer has arrived
				if (nextNormal == 0)
				{
					// add the new arrival to the lane
					tempData = clearData ();
					custNum++;
					printf ("Customer #%d has arrived.\n", custNum);
					if (isSaving)
						fprintf (outFile, "Customer #%d has arrived.\n", custNum);
					tempData.customerNumber = custNum;
					tempData.serviceTime = getServiceTime (false);
					if (totalNormal == 0)
						totalNormal = tempData.serviceTime;
					else
						totalNormal = totalNormal + tempData.serviceTime;
					tempData.totalTime = totalNormal;
					if (isEmpty (normalLane))
						tempData.serviceTime++;
					enqueue (&normalLane, tempData);
					// get a new arrival time
					nextNormal = getArrivalTime (false);
				}
				// check if a new express customer has arrived
				if (nextExpress == 0)
				{
					// add a new arrival to the lane
					tempData = clearData ();
					custNum++;
					printf ("Customer #%d has arrived.\n", custNum);
					if (isSaving)
						fprintf (outFile, "Customer #%d has arrived.\n", custNum);
					tempData.customerNumber = custNum;
					tempData.serviceTime = getServiceTime (true);
					if (totalExpress == 0)
						totalExpress = tempData.serviceTime;
					else
						totalExpress = totalExpress + tempData.serviceTime;
					tempData.totalTime = totalExpress;
					if (isEmpty (expressLane))
						tempData.serviceTime++;
					enqueue (&expressLane, tempData);
					// get a new arrival time
					nextExpress = getArrivalTime (true);
				}
				// SERVICE
				// Normal Line
				if (!isEmpty (normalLane))
				{
					// decrement current service time
					normalLane.pHead->data.serviceTime--;
					// if they are done, dequeue the customer
					if (0 == normalLane.pHead->data.serviceTime)
					{
						printf ("Customer #%d has finished checking out.\n", normalLane.pHead->data.customerNumber);
						if (isSaving)
							fprintf (outFile, "Customer #%d has finished checking out.\n", normalLane.pHead->data.customerNumber);
						dequeue (&normalLane);
					}
				}
				// Express Line
				if (!isEmpty (expressLane))
				{
					// decrement current service time
					expressLane.pHead->data.serviceTime--;
					// if they are done, dequeue the customer
					if (0 == expressLane.pHead->data.serviceTime)
					{
						printf ("Customer #%d has finished checking out.\n", expressLane.pHead->data.customerNumber);
						if (isSaving)
							fprintf (outFile, "Customer #%d has finished checking out.\n", expressLane.pHead->data.customerNumber);
						dequeue (&expressLane);
					}
				}

				// 10 TICK PRINTOUT
				if ((ticks%10) == 0)
				{
					// print report message and current queues
					printf ("\n\n******** TEN MINUTE REPORT ********\n");
					if (isSaving)
						fprintf (outFile, "\n\n******** TEN MINUTE REPORT ********\n");
					printf ("******** NORMAL LANE ********\n");
					if (isSaving)
						fprintf (outFile, "******** NORMAL LANE ********\n");
					printQueueRecursive (normalLane, outFile, isSaving);
					printf ("******** EXPRESS LANE ********\n");
					if (isSaving)
						fprintf (outFile, "******** EXPRESS LANE ********\n");
					printQueueRecursive (expressLane, outFile, isSaving);
					printf ("\n");
					if (isSaving)
						fprintf (outFile, "\n");
				}
				// check for keys being pressed
				keys = getKeySelected ();
				// is the spacebar being pressed?
				if (keys.key == '~')
				{
					if (keys.specialKey == 'S')
					{
						// if it is, end the simulation
						sim_state = 2;
					}
				}
				// is the simulation being paused?
				else if (keys.key == 'P')
				{
					// if it is, pause the simulation
					pause_clear (true, false);
				}
			}
			// if we *are* at the end of a simulation, end the simulation
			else
			{
				sim_state = 2;
			}
		}
		// End of Simulation
		else
		{
			// print final report
			printf ("\n******** END OF SIMULATION ********\n");
			if (isSaving)
				fprintf (outFile, "******** END OF SIMULATION ********\n");
			printf ("Simulation ran for %d minute(s).\n", ticks);
			if (isSaving)
				fprintf (outFile, "Simulation ran for %d minute(s).\n", ticks);
			printf ("NOTE: Total times counts in those people who are still in line at the time of the end of the simulation.\n");
			if (isSaving)
				fprintf (outFile, "NOTE: Total times count in those people who are still in line at end of the simulation.\n");
			printf ("Normal Lane Total Time: %d minute(s).\n", totalNormal);
			if (isSaving)
				fprintf (outFile, "Normal Lane Total Time: %d minute(s).\n", totalNormal);
			printf ("Express Lane Total Time: %d minute(s).\n", totalExpress);
			if (isSaving)
				fprintf (outFile, "Express Lane Total Time: %d minute(s).\n", totalExpress);
			// did the normal lane take longer? Say so
			if (totalNormal > totalExpress)
			{
				totalDifference = totalNormal - totalExpress;
				printf ("Express Lane was more efficient (by %d minute(s)).\n", totalDifference);
				if (isSaving)
					fprintf (outFile, "Express Lane was more efficient (by %d minute(s)).\n", totalDifference);
			}
			// did the express lane take longer? Say so
			else if (totalNormal < totalExpress)
			{
				totalDifference = totalExpress - totalNormal;
				printf ("Normal Lane was more efficient (by %d minute(s)).\n", totalDifference);
				if (isSaving)
					fprintf (outFile, "Normal Lane was more efficient (by %d minute(s)).\n", totalDifference);
			}
			// did neither lane take longer? say so
			else
			{
				printf ("Neither Lane was more efficient.\n");
				if (isSaving)
					fprintf (outFile, "Neither Lane was more efficient.\n");
			}
			printf ("\n");
			// if the program is saving, tell the user that
			if (isSaving)
			{
				printf ("A record has been made of this simulation.\n");
				fclose (outFile);
			}
			// end the simulation loop (end the function and goto main menu)
			sim_state = -1;
		}
	}
}

/*************************************************************
 * Function: getArrivalTime ()
 * Created: February 17th, 2011
 * Last Revised: February 22nd, 2012
 * Description: This function gets a random arrival time
 * Preconditions: an arrival time is needed
 * Postconditions: an arrival time is gotten
 *************************************************************/
int getArrivalTime (Bool isExpress)
{
	int arrivalTime = 0;
	// if the service time should be an express type
	if (isExpress)
	{
		arrivalTime = getRandomNumber (1, 5);
	}
	// otherwise, it must be a normal type
	else
	{
		arrivalTime = getRandomNumber (3, 8);
	}
	// return the time
	return arrivalTime;
}

/*************************************************************
 * Function: getServiceTime ()
 * Created: February 17th, 2011
 * Last Revised: February 22nd, 2012
 * Description: This function gets a random service time
 * Preconditions: an service time is needed
 * Postconditions: an service time is gotten
 *************************************************************/
int getServiceTime (Bool isExpress)
{
	int serviceTime = 0;
	// if the service time should be an express type
	if (isExpress)
	{
		serviceTime = getRandomNumber (1, 5);
	}
	// otherwise, it must be a normal type
	else
	{
		serviceTime = getRandomNumber (3, 8);
	}
	// return the time
	return serviceTime;
}

/*************************************************************
 * Function: clearData ()
 * Created: February 17th, 2011
 * Last Revised: February 22nd, 2012
 * Description: This function returns a cleared CustomerData struct.
 *					Used "just in case" (had problems with one of the
 *					structs at one point).
 * Preconditions: a cleared CustomerData struct is needed
 * Postconditions: a cleared CustomerData struct is gotten
 *************************************************************/
CustomerData clearData (void)
{
	// create/return cleared CustomerData
	CustomerData tempData = {0, 0, 0};
	return tempData;
}