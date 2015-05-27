/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * Standard Menu System
 * Created: September 28th, 2011
 * Last Revised: March 2nd, 2012
 * Description: This function set allows a menu to be generated and a valid answer
 *							to be selected and returned.
 *
 * File Description: "menu_system.h" contains the various includes and function
 *									prototypes which control the menu_system.c file functions.
 *********************************************************************************************/

#ifndef MENU_SYSTEM
#define MENU_SYSTEM

// includes
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;
//using string::find_first_not_of;
//using string::substr;

// Typedef
typedef struct keyInput
{
	char key;
	char specialKey;
} KeyInput;

// functions
int display_menu (int inputMode, int itemPreType, char itemPreChar, int minItem, int numItems, string itemDelim, string programTitle, string menuTitle, string menuItems);
KeyInput getKeySelected (void);
int char_convert (char value);
char char_reverse_convert (int value, int is_upper);
string getToken (int &startPosition, string baseString, string delim);

#endif