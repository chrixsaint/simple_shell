#include "shell.h"

/**
 * free_string_array - Frees an array of strings.
 * @pp: The array of strings to be freed.
 *
 * This function releases the memory occupied by an
 * array of strings. It iterates through the array and
 * frees each individual string, and finally, the array itself.
 *
 * Return: None.
 */

void free_string_array(char **pp)
{
	char **aii;

	aii = pp;
	if (pp == NULL)
	{
		return;
	}
	while (*pp)
		free(*pp++);
	free(aii);
}


