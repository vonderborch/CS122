/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 121, Fall 2011; Lab Section 3
 * Standard Menu System
 * Created: October 5th, 2011
 * Last Revised: November 21st, 2011
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
#include <windows.h>

// Typedef
typedef struct keyInput
{
	char key;
	char specialKey;
} KeyInput;

// functions
int display_standard_menu (int menu_type, int min_items, int num_items, char menu_title[], char menu_items[][128]);
int display_selector_menu (int min_items, int num_items, char menu_title[], char menu_items[][128]);
KeyInput getKeySelected (void);
int char_convert (char value);
char char_reverse_convert (int value, int is_upper);
int is_valid_item (int option, int num_items, int min_items);

#endif