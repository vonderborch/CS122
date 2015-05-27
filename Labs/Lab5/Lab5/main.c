#include "lab5.h"

int main (int argc, char *argv[])
{
	TreeNode *pTree = NULL;
	FILE *morseFile = NULL, *inFile = NULL, *outFile = NULL;
	int i = 0;
	char tempLetter, tempMorse[16], message[512];
	Bool success = false;

	if (argc < 4)
	{
		printf ("Invalid input and/or output file paths.\n");
		printf ("Morse/Letter Translation File, Input File, Output File\n\n");
	}
	else
	{
		morseFile = fopen (argv[1], "r");
		inFile = fopen (argv[2], "r");
		outFile = fopen (argv[3], "w");

		printf ("Compiling morse conversion...");
		while (!feof (morseFile))
		{
			fscanf (morseFile, " %c %s", &tempLetter, &tempMorse);
			success = insertNode (&pTree, tempLetter, tempMorse);
			for (i = 0; i < 16; i++)
			{
				tempMorse[i] = '\0';
			}
		}
		printf ("Compiled!\n");

		printTree (pTree);

		fget (&message);

		fprintf (outFile, "%s", convertToMorse (pTree, message));

		fclose (morseFile);
		fclose (inFile);
		fclose (outFile);
	}

	return 0;
}