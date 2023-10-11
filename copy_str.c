#include "shell.h"

/**
 * copy_str - Copies a string from source to destination.
 * @dest: The destination string.
 * @src: The source string.
 *
 * This function copies the content of the source string `src`
 * to the destination string `dest`.
 *
 * Return: A pointer to the destination string `dest`.
 */

char *copy_str(char *dest, char *src)
{
	int aii;

	if (dest == src || src == 0)
	{
		return (dest);
	}
	for (aii = 0; src[aii]; aii++)
	{
		dest[aii] = src[aii];
	}
	dest[aii] = 0;
	return (dest);
}
