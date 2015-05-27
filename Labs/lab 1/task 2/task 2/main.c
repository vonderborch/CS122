#include "task2.h"

int main (void)
{
	char string_to_reverse[6] = "Glenn",
		*string_a_copy = NULL,
		string_to_reverse_copy[6] = "Glenn";
	printf ("PART A\n");
	printf ("String to Reverse: %s\n", string_to_reverse);
	string_a_copy = string_reverse (string_to_reverse);
	printf ("String Reversed: %s\n\n", string_a_copy);
	return 0;
}