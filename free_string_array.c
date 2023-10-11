#include "shell.h"

/**
 * free_string_array - frees a string of strings
 * @pp: string of strings
 * Return: nothing
 * realloc.c
 */
void free_string_array(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}


