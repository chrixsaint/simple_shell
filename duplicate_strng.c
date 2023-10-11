#include "shell.h"


/**
 * duplicate_strng - Duplicates a string.
 * @str: The string to duplicate.
 *
 * This function duplicates the input string `str`
 * and returns a pointer to the duplicated string.
 *
 * Return: A pointer to the duplicated string or NULL
 * if memory allocation fails.
 * string1.c
 */
char *duplicate_strng(const char *str)
{
	char *reset;
	int lentt = 0;

	if (!str)
	{
		return (NULL);
	}
	while (*str++)
	{
		lentt++;
	}
	reset = malloc(sizeof(char) * (lentt + 1));
	if (reset == NULL)
	{
		return (NULL);
	}
	for (lentt++; lentt--;)
		reset[lentt] = *--str;
	return (reset);
}


