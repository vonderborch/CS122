/**********************************************************************************************
 * Programmer: Christian Webber
 * Class: CptS 122, Spring 2012; Lab Section 3
 * PA1, Task 1
 * Created: January 27th, 2012
 * Last Revised: February 2nd, 2012
 *
 * File Description: "functions.c" contains the sub-functions for the program.
 *********************************************************************************************/

#include "PA2.h"

/*************************************************************
 * Function: addSong ()
 * Created: January 27th, 2012
 * Last Revised: February 2nd, 2012
 * Description: This function adds a song to the program
 * Input parameters: Songs node
 * Returns: True/False on success status
 * Preconditions: a song needs to be added
 * Postconditions: a song has been added
 *************************************************************/
Bool addSong (Node **pSongs)
{
	Bool success = false;
	Node *pNew = NULL;
	int option = 0;

	// allocate memory
	pNew = (Node *) malloc (sizeof (Node));

	// if it was allocated, create a node
	if (pNew != NULL)
	{
		// get song info
		printf ("Song Information?\n");
		pNew->data = getSongInfo ();

		// set next/prev node info
		pNew->pNext = *pSongs;
		pNew->pPrev = NULL;
		*pSongs = pNew;

		success = true;
	}

	return success;
}

/*************************************************************
 * Function: editSong ()
 * Created: January 27th, 2012
 * Last Revised: February 2nd, 2012
 * Description: This function edits a song
 * Input parameters: boolean on whether this is a full
 *								edit or not. Songs node.
 * Returns: True/False on success status
 * Preconditions: a song needs to be edited
 * Postconditions: a song has been edited
 *************************************************************/
Bool editSong (Bool isRating, Node **pSongs)
{
	Node *pCurr = NULL, *pPrev = NULL, *pNext = NULL, *pNew = NULL;
	Bool success = false;
	int option = 0;
	Song songData;

	// ask for song info
	printf ("Enter Song Info:\nLeave Fields Blank (or a 0) but Desired for Finding Song\nWill Select First Song in List\n");
	songData = getSongInfo ();

	// get the node with the data recieved
	// keep repeating until node is found
	if (songData.album != "")
	{
		while ((pCurr != NULL) && (pCurr->data.album != songData.album))
		{
			pCurr = pCurr->pNext;
		}
	}
	else if (songData.artist != "")
	{
		while ((pCurr != NULL) && (pCurr->data.artist != songData.artist))
		{
			pCurr = pCurr->pNext;
		}
	}
	else if (songData.title != "")
	{
		while ((pCurr != NULL) && (pCurr->data.title != songData.title))
		{
			pCurr = pCurr->pNext;
		}
	}
	else if (songData.genre != "")
	{
		while ((pCurr != NULL) && (pCurr->data.genre != songData.genre))
		{
			pCurr = pCurr->pNext;
		}
	}
	else if (songData.timesPlayed != 0)
	{
		while ((pCurr != NULL) && (pCurr->data.timesPlayed != songData.timesPlayed))
		{
			pCurr = pCurr->pNext;
		}
	}
	else if (songData.songLength.minutes != 0)
	{
		while ((pCurr != NULL) && (pCurr->data.songLength.minutes != songData.songLength.minutes))
		{
			pCurr = pCurr->pNext;
		}
	}
	else if (songData.songLength.seconds != 0)
	{
		while ((pCurr != NULL) && (pCurr->data.songLength.seconds != songData.songLength.seconds))
		{
			pCurr = pCurr->pNext;
		}
	}
	else
	{
		while ((pCurr != NULL) && (pCurr->data.rating != songData.rating))
		{
			pCurr = pCurr->pNext;
		}
	}

	// if the node has been found, print the Node data
	if (pCurr != NULL)
	{
		printf ("%s\n%s\nBy: %s\n%d: %d\n%s\n%d\n%d / 5\n",
			pCurr->data.title, pCurr->data.album, pCurr->data.artist,
			pCurr->data.songLength.minutes, pCurr->data.songLength.seconds,
			pCurr->data.genre, pCurr->data.timesPlayed, pCurr->data.rating);
		// if this is supposed to be a rating edit, ask and get for a new rating
		if (isRating == true)
		{
			*pSongs = pCurr;
			printf ("New Rating? ");
			(*pSongs)->data.rating = getIntInputCheck (1, 5);
			success = true;
		}
		// otherwise...
		else
		{
			// display a menu asking if the song is to be edited
			option = display_menu (2, 2, ':', 1, 2, ";", "Digital Music Manager", "Edit this Song?",
					"Yes;No");
			// if it is, get the new info
			if (option == 1)
			{
				*pSongs = pCurr;
				printf ("Enter Song Info:\n");
				(*pSongs)->data = getSongInfo ();
				success = true;
			}
		}
	}
	return success;
}

/*************************************************************
 * Function: deleteSong ()
 * Created: January 27th, 2012
 * Last Revised: February 2nd, 2012
 * Description: This function delete a song
 * Input parameters: Songs node
 * Returns: True/False on success status
 * Preconditions: a song needs to be deleted
 * Postconditions: a song has been deleted
 *************************************************************/
Bool deleteSong (Node **pSongs)
{
	Node *pCurr = NULL, *pPrev = NULL, *pNext = NULL;
	Bool success = false;
	Song songData;

	// ask for song info
	printf ("Enter Song Info:\nLeave Fields Blank (or a 0) but Desired for Finding Song\nWill Select First Song in List\n");
	songData = getSongInfo ();

	// get the node with the data recieved
	// keep repeating until node is found
	printf ("Enter Song Info:\nLeave Fields Blank (or a 0) but Desired for Finding Song\nWill Select First Song in List\n");
	songData = getSongInfo ();
	pCurr = *pSongs;
	if (songData.album != "")
	{
		while ((pCurr != NULL) && (pCurr->data.album != songData.album))
		{
			pCurr = pCurr->pNext;
		}
	}
	else if (songData.artist != "")
	{
		while ((pCurr != NULL) && (pCurr->data.artist != songData.artist))
		{
			pCurr = pCurr->pNext;
		}
	}
	else if (songData.title != "")
	{
		while ((pCurr != NULL) && (pCurr->data.title != songData.title))
		{
			pCurr = pCurr->pNext;
		}
	}
	else if (songData.genre != "")
	{
		while ((pCurr != NULL) && (pCurr->data.genre != songData.genre))
		{
			pCurr = pCurr->pNext;
		}
	}
	else if (songData.timesPlayed != 0)
	{
		while ((pCurr != NULL) && (pCurr->data.timesPlayed != songData.timesPlayed))
		{
			pCurr = pCurr->pNext;
		}
	}
	else if (songData.songLength.minutes != 0)
	{
		while ((pCurr != NULL) && (pCurr->data.songLength.minutes != songData.songLength.minutes))
		{
			pCurr = pCurr->pNext;
		}
	}
	else if (songData.songLength.seconds != 0)
	{
		while ((pCurr != NULL) && (pCurr->data.songLength.seconds != songData.songLength.seconds))
		{
			pCurr = pCurr->pNext;
		}
	}
	else
	{
		while ((pCurr != NULL) && (pCurr->data.rating != songData.rating))
		{
			pCurr = pCurr->pNext;
		}
	}
	// if the node has been found...delete the node and update the list
	if (pCurr != NULL)
	{
		*pSongs = pCurr;
		pPrev = (*pSongs)->pPrev;
		pNext = (*pSongs)->pNext;
		free (*pSongs);
		*pSongs = pPrev;
		(*pSongs)->pNext = pNext;
		*pSongs = pNext;
		(*pSongs)->pPrev = pPrev;
		success = true;
	}
	return success;
}

/*************************************************************
 * Function: sortSongs ()
 * Created: January 27th, 2012
 * Last Revised: February 2nd, 2012
 * Description: This function sorts the songs
 * Input parameters: Songs node, sort method.
 * Returns: True/False on success status
 * Preconditions: the songs need to be sorted
 * Postconditions: the songs have been sorted
 *************************************************************/
Bool sortSongs (Node **pSongs, int sortMethod)
{
	Bool success = false;
	Node *pPrevBU = NULL, *pPrev = NULL,
		*pTemp = NULL, *pTempBU = NULL, *pCurr = NULL;
	int i = 0, indexU = 0, indexC = 1, unSorted = 0,
		wordCount = 0, compareValue = 0;

	if (*pSongs != NULL)
	{
		pCurr = *pSongs;
		// Count up total Songs
		while (pCurr != NULL)
		{
			wordCount++;
			pCurr = pCurr->pNext;
		}

		indexU = wordCount;
		unSorted = wordCount * wordCount;
		pCurr = *pSongs;

		while (unSorted > 0)
		{
			*pSongs = pCurr;
			while (*pSongs != NULL)
			{
				// not first in list
				if ((*pSongs)->pPrev != NULL)
				{
					// title
					if (sortMethod == 1)
					{
						compareValue = strcmp ((*pSongs)->data.title, (*pSongs)->pNext->data.title);
					}
					// genre
					else if (sortMethod == 2)
					{
						compareValue = strcmp ((*pSongs)->data.genre, (*pSongs)->pNext->data.genre);
					}
					// rating
					else if (sortMethod == 3)
					{
						compareValue = (*pSongs)->data.rating - (*pSongs)->pNext->data.rating;
					}
					// perform sort operation if required
					if (compareValue > 0)
					{
						pTemp = *pSongs;
						pTempBU = pTemp;
						pPrev = (*pSongs)->pPrev;
						pPrevBU = pPrev;

						if (pTemp->pNext != NULL)
						{
							pTemp->pNext = pPrev;
						}
						else
						{
							pTemp->pNext = NULL;
						}
						if (pTemp->pPrev != NULL)
						{
							pTemp->pPrev = pPrev->pPrev;
						}
						else
						{
							pTemp->pPrev = NULL;
						}

						if (pPrev->pNext != NULL)
						{
							pPrev->pNext = pTemp->pNext;
						}
						else
						{
							pPrev->pNext = NULL;
						}
						if (pPrev->pPrev != NULL)
						{
							pPrev->pPrev = pTemp;
						}
						else
						{
							pPrev->pPrev = NULL;
						}

						*pSongs = pPrev;
						(*pSongs)->pPrev = pTemp;
						*pSongs = (*pSongs)->pNext;
					}
					else
					{
						unSorted--;
					}
				}
				*pSongs = (*pSongs)->pNext;
			}
		}
		success = true;
	}
	else
	{
		success = true;
	}

	return success;
}

/*************************************************************
 * Function: displaySongs ()
 * Created: January 27th, 2012
 * Last Revised: February 2nd, 2012
 * Description: This function displays the songs
 * Input parameters: Songs node
 * Returns: None
 * Preconditions: the songs need to be shown
 * Postconditions: the songs have been shown
 *************************************************************/
void displaySongs (Node *pSongs)
{
	int option = 0;
	Song songData;
	option = display_menu (2, 2, ':', 1, 3, ";", "Digital Music Manager", "Display Songs",
				"<- Go Back;Display Single Song;Display All Songs");
	// Display Single Song
	if (option == 2)
	{
		// ask/get song info
		printf ("Enter Song Info:\nLeave Fields Blank (or a 0) but Desired for Finding Song\nWill Select First Song in List\n");
		songData = getSongInfo ();
		// find the node with the inputted data
		if (songData.album != "")
		{
			while ((pSongs != NULL) && (pSongs->data.album != songData.album))
			{
				pSongs = pSongs->pNext;
			}
		}
		else if (songData.artist != "")
		{
			while ((pSongs != NULL) && (pSongs->data.artist != songData.artist))
			{
				pSongs = pSongs->pNext;
			}
		}
		else if (songData.title != "")
		{
			while ((pSongs != NULL) && (pSongs->data.title != songData.title))
			{
				pSongs = pSongs->pNext;
			}
		}
		else if (songData.genre != "")
		{
			while ((pSongs != NULL) && (pSongs->data.genre != songData.genre))
			{
				pSongs = pSongs->pNext;
			}
		}
		else if (songData.timesPlayed != 0)
		{
			while ((pSongs != NULL) && (pSongs->data.timesPlayed != songData.timesPlayed))
			{
				pSongs = pSongs->pNext;
			}
		}
		else if (songData.songLength.minutes != 0)
		{
			while ((pSongs != NULL) && (pSongs->data.songLength.minutes != songData.songLength.minutes))
			{
				pSongs = pSongs->pNext;
			}
		}
		else if (songData.songLength.seconds != 0)
		{
			while ((pSongs != NULL) && (pSongs->data.songLength.seconds != songData.songLength.seconds))
			{
				pSongs = pSongs->pNext;
			}
		}
		else
		{
			while ((pSongs != NULL) && (pSongs->data.rating != songData.rating))
			{
				pSongs = pSongs->pNext;
			}
		}
		if (pSongs != NULL)
		{
			printf ("%s\n%s\nBy: %s\n%d: %d\n%s\n%d\n%d / 5\n",
					pSongs->data.title, pSongs->data.album, pSongs->data.artist,
					pSongs->data.songLength.minutes, pSongs->data.songLength.seconds,
					pSongs->data.genre, pSongs->data.timesPlayed, pSongs->data.rating);
			pause_clear (true, false);
		}
	}
	// Display All Songs
	else if (option == 3)
	{
		option = display_menu (2, 2, ':', 1, 2, ";", "Digital Music Manager", "Display Order?",
				"Ascending;Decending");
		// Ascending Order
		if (option == 1)
		{
			while (pSongs->pNext != NULL)
			{
				pSongs = pSongs->pNext;
			}
			while (pSongs != NULL)
			{
				printf ("%s\n%s\nBy: %s\n%d: %d\n%s\n%d\n%d / 5\n",
					pSongs->data.title, pSongs->data.album, pSongs->data.artist,
					pSongs->data.songLength.minutes, pSongs->data.songLength.seconds,
					pSongs->data.genre, pSongs->data.timesPlayed, pSongs->data.rating);
				pause_clear (true, false);
				pSongs = pSongs->pPrev;
			}
		}
		// Decending Order
		else
		{
			while (pSongs != NULL)
			{
				printf ("%s\n%s\nBy: %s\n%d: %d\n%s\n%d\n%d / 5\n",
					pSongs->data.title, pSongs->data.album, pSongs->data.artist,
					pSongs->data.songLength.minutes, pSongs->data.songLength.seconds,
					pSongs->data.genre, pSongs->data.timesPlayed, pSongs->data.rating);
				pause_clear (true, false);
				pSongs = pSongs->pNext;
			}
		}
	}
}

/*************************************************************
 * Function: storeSongs ()
 * Created: January 27th, 2012
 * Last Revised: February 2nd, 2012
 * Description: This function stores the song
 * Input parameters: Songs node, file
 * Returns: None
 * Preconditions: the songs need to be stored
 * Postconditions: the songs have been stored
 *************************************************************/
void storeSongs (Node *pSongs, FILE *ioFile)
{
	// cycle through all nodes printing them to the music file
	while (pSongs != NULL)
	{
		fprintf (ioFile, "%s %s %s %s %d %d %d %d\n",
			pSongs->data.artist, pSongs->data.album, pSongs->data.title, pSongs->data.genre,
			pSongs->data.songLength.minutes, pSongs->data.songLength.seconds,
			pSongs->data.timesPlayed, pSongs->data.rating);
		pSongs = pSongs->pNext;
	}
}

/*************************************************************
 * Function: loadSongs ()
 * Created: January 27th, 2012
 * Last Revised: February 2nd, 2012
 * Description: This function loads the songs
 * Input parameters: Songs node, file
 * Returns: True/False on success status
 * Preconditions: the songs need to be loaded
 * Postconditions: the songs have been loaded
 *************************************************************/
Bool loadSongs (Node **pSongs, FILE *ioFile)
{
	Bool success = false, checking = true;
	Song songData;
	// cycle through file until all data has been read and added to the Nodes
	while ((!feof (ioFile)) && (checking == true))
	{
		fscanf (ioFile, "%s %s %s %s %d %d %d %d\n",
			&songData.artist, &songData.album, &songData.title, &songData.genre,
			&songData.songLength.minutes, &songData.songLength.seconds,
			&songData.timesPlayed, &songData.rating);
		success = addNode (&*pSongs, songData);
		if (success == false)
			checking = false;
	}
	if (success == true)
	{
		// sort the music
		sortSongs (&*pSongs, display_menu (2, 2, ':', 1, 3, ";", "Digital Music Manager", "Choose a Sort Order...",
						"Sort by Song Title;Sort by Genre;Sort by Rating"));
	}
	return success;
}

/*************************************************************
 * Function: addNode ()
 * Created: January 27th, 2012
 * Last Revised: February 2nd, 2012
 * Description: This function adds a node
 * Input parameters: Songs node, song data
 * Returns: True/False on success status
 * Preconditions: a node must be created
 * Postconditions: a node has ben created
 *************************************************************/
Bool addNode (Node **pSongs, Song songData)
{
	Bool success = false;
	Node *pNew = NULL;

	// allocate memory
	pNew = (Node *) malloc (sizeof (Node));

	// if the memory was allocated, insert the data
	if (pNew != NULL)
	{
		pNew->pNext = *pSongs;
		pNew->pPrev = NULL;
		*pSongs = pNew;

		success = true;
	}

	return success;
}

/*************************************************************
 * Function: getSongInfo ()
 * Created: January 27th, 2012
 * Last Revised: February 2nd, 2012
 * Description: This function gets the song info
 * Input parameters: None
 * Returns: Song data
 * Preconditions: info for a song is needed
 * Postconditions: info for a song is gotten
 *************************************************************/
Song getSongInfo (void)
{
	Song tempSongInfo;
	char artist[32],
		 album[32],
		 title[32],
		 genre[32];
	Length songLength;
	int timesPlayed = 0, rating = 0;
	Bool success = true;

	// ask for all song info
	printf ("Artist? ");
	scanf ("%s", &artist);
	printf ("Album Title? ");
	scanf ("%s", &album);
	printf ("Song Title? ");
	scanf ("%s", &title);
	printf ("Genre? ");
	scanf ("%s", &genre);
	printf ("Song Length (whole minutes)? ");
	songLength.minutes = getIntInputCheck (0, 100000);
	printf ("Song Length (whole seconds)? ");
	songLength.seconds = getIntInputCheck (0, 100000);
	printf ("Number of Times Played? ");
	timesPlayed = getIntInputCheck (0, 100000);
	printf ("Rating (1 - 5)? ");
	rating = getIntInputCheck (0, 5);

	// allocate all necessary memory for the strings
	tempSongInfo.artist = (char *) malloc ((strlen (artist) + 1) * sizeof (char));
	if (tempSongInfo.artist == NULL)
	{
		success = false;
	}
	tempSongInfo.album = (char *) malloc ((strlen (album) + 1) * sizeof (char));
	if (tempSongInfo.album == NULL)
	{
		success = false;
	}
	tempSongInfo.title = (char *) malloc ((strlen (title) + 1) * sizeof (char));
	if (tempSongInfo.title == NULL)
	{
		success = false;
	}
	tempSongInfo.genre = (char *) malloc ((strlen (genre) + 1) * sizeof (char));
	if (tempSongInfo.genre == NULL)
	{
		success = false;
	}

	// copy the strings into the Info struct
	if (success == true)
	{
		strcpy (tempSongInfo.artist, artist);
		strcpy (tempSongInfo.album, album);
		strcpy (tempSongInfo.title, title);
		strcpy (tempSongInfo.genre, genre);
	}
	else
	{
		strcpy (tempSongInfo.title, "NAN");
	}

	return tempSongInfo;
}