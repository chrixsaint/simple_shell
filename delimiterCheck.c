#include "shell.h"


/**
 * delimiterCheck - Checks if a character is a delimiter by
 * comparing it to a given delimiter string.
 * @c: The character to check.
 * @delim: The delimiter string containing delimiting characters.
 *
 * This function checks if the character `c` is
 * present in the delimiter string `delim`.
 *
 * Return: 1 if `c` is a delimiter, 0 if not.
 * _atoic.c
 */

int delimiterCheck(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
		{
			return (1);
		}
	return (0);
}
