#include "shell.h"


/**
 * concatenateLimitedString - Concatenates two strings with a length limit.
 * @dest: The destination string where the result will be stored.
 * @src: The source string to be concatenated.
 * @n: The maximum number of characters from src to concatenate.
 *
 * This function appends up to `n` characters from the source
 * string `src` to the end of the destination string `dest`.
 * It ensures the resulting string remains null-terminated and
 * does not exceed the allocated buffer size.
 *
 * Return: A pointer to the destination string `dest`.
 */

char *concatenateLimitedString(char *dest, char *src, int n)
{
	char *s;
	int aii, jai;

	s = dest;
	jai = 0;
	for (aii = 0; dest[aii] != '\0'; aii++)
		;
	while (src[jai] != '\0' && jai < n)
	{
		dest[aii] = src[jai];
		aii++;
		jai++;
	}
	if (jai < n)
	{
		dest[aii] = '\0';
	}
	return (s);
}


