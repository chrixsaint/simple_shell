#include "shell.h"
/**
 * prefix_match - checks needle str in given stack
 * @haystack: str to b searched
 * @needle: substr to be traced
 * Return: returns ptr to next char.
 * string.c
 */
char *prefix_match(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
		{
			return (NULL);
		}
	return ((char *)haystack);
}

