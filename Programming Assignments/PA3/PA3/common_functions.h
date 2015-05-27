/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 121, Fall 2011; Lab Section 3
 * Common Functions
 * Created: November 30th, 2011
 * Last Revised: January 23rd, 2012
 * Description: This function consists of some common functions
 *
 * File Description: "common_functions.h" contains the various includes and function
 *									prototypes which control the common_functions.c file functions.
 *********************************************************************************************/
#ifndef COMMON_FUNCTIONS
#define COMMON_FUNCTIONS

// includes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum bool
{
	false,
	true
} Bool;

// functions
void pause_clear (Bool shouldPause, Bool shouldClear);
void seedRandomGenerator (Bool assignTime, int randomSeed);
int getRandomNumber (int minNum, int maxNum);
int getIntInputCheck (int minGood, int maxGood);
double getDoubleInputCheck (double minGood, double maxGood);
void printMessage (char message[128], Bool shouldPause, Bool shouldClear);

#endif