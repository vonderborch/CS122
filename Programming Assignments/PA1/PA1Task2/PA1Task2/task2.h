/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * PA1, Task 2
 * Created: January 22nd, 2012
 * Last Revised: January 24th, 2012
 *
 * File Description: "task2.h" contains the various includes, typedefs, and function
 *									prototypes which control the project uses.
 *********************************************************************************************/

#ifndef TASK_2
#define TASK_2

// libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// functions
void checkPalindrome (void);
void remove_punc (int str_length, char *source, char *destination);
int determine_palindrome (int left, int right, char string[]);
void pause_clear (int pause, int clear);

#endif