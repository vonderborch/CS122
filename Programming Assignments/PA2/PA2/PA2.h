/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * PA1, Task 1
 * Created: January 27th, 2012
 * Last Revised: February 2nd, 2012
 *
 * File Description: "PA2.h" contains the includes and definitions of the various
 *									peices needed for the program.
 *********************************************************************************************/

#ifndef PA_2
#define PA_2

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common_functions.h"
#include "menu_system.h"

// song length struct
typedef struct length
{
	int minutes;
	int seconds;
} Length;

// song info struct
typedef struct song
{
	char *artist;
	char *album;
	char *title;
	char *genre;
	Length songLength;
	int timesPlayed;
	int rating;
} Song;

// node struct
typedef struct node
{
	Song data;
	struct node *pPrev;
	struct node *pNext;
} Node;

// functions
Bool addSong (Node **pSongs);
Bool editSong (Bool isRating, Node **pSongs);
Bool deleteSong (Node **pSongs);
Bool sortSongs (Node **pSongs, int sortMethod);
void displaySongs (Node *pSongs);
void storeSongs (Node *pSongs, FILE *ioFile);
Bool loadSongs (Node **pSongs, FILE *ioFile);
Song getSongInfo (void);

#endif