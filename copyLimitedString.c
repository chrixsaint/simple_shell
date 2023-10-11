#include "shell.h"


/**
 * copyLimitedString - Copies a limited number of characters
 * from a src string to a destination.
 * @dest: The destination string to be copied to.
 * @src: The source string.
 * @n: The maximum number of characters to be copied.
 *
 * This function copies a maximum of `n` characters from
 * the source string `src` to the destination
 * string `dest`. It ensures that `dest` is null-terminated.
 *
 * Return: A pointer to the destination string `dest`.
 */

char *copyLimitedString(char *dest, char *src, int n)
{
	char *s;
	int aii, jaii;

	s = dest;
	for (aii = 0; src[aii] != '\0' && aii < n - 1; aii++)
	{
		dest[aii] = src[aii];
	}
	if (aii < n)
	{
		jaii = aii;
		while (jaii < n)
		{
			dest[jaii] = '\0';
			jaii++;
		}
	}
	return (s);
}
