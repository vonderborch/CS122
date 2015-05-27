#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct partC
{
	int characterCount[26];
} PartC;

char* string_reverse (char string[]);
PartC characterCounter (void);