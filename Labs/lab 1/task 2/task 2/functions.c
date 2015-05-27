#include "task2.h"

char* string_reverse (char string[])
{
	char temp = '\0';
	int i = 0, length = 0;

	for (i = 0; string[i] != '/0'; i++);
	length = i;

	for (i = 0; i < (length / 2); i++)
	{
		temp = string[i];
		string[i] = string[length - 1 - i];
		string[length - 1 - i] = temp;
	}
	return string;
}

PartC characterCounter (void)
{
	PartC characters;
	FILE *inFile = NULL;
	char tempChar = '\0';
	int charNum = 0;
	inFile = fopen ("characters.txt", "r");

	if (inFile == NULL)
	{
		printf ("No file to read.");
	}
	else
	{
		tempChar = fscanf (inFile, " %c");
		while (!feof (inFile))
		{
			charNum = (int)tempChar;
			charNum -= 39;
			characters.characterCount[charNum]++;
			tempChar = fscanf (inFile, " %c");
		}
	}
	return characters;
}