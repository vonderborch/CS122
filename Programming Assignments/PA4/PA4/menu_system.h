/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 121, Fall 2011; Lab Section 3
 * Standard Menu System
 * Created: September 28th, 2011
 * Last Revised: January 25th, 2012
 * Description: This function set allows a menu to be generated and a valid answer
 *							to be selected and returned.
 *
 * File Description: "menu_system.h" contains the various includes and function
 *									prototypes which control the menu_system.c file functions.
 *********************************************************************************************/

#ifndef MENU_SYSTEM
#define MENU_SYSTEM

// includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Typedef
typedef struct keyInput
{
	char key;
	char specialKey;
} KeyInput;

// functions
int display_menu (int inputMode, int itemPreType, char itemPreChar, int minItem, int numItems, char itemDelim[], char programTitle[], char menuTitle[], char menuItems[]);
KeyInput getKeySelected (void);
int char_convert (char value);
char char_reverse_convert (int value, int is_upper);

#endif