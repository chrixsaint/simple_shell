#include "shell.h"

/**
 * checkAlphabetic - Checks if a character is alphabetic (a-z or A-Z)
 * @c: The character to be checked.
 *
 * This function checks if the character 'c' is an alphabetic
 * character, meaning it falls within the range 'a' to 'z' or 'A' to 'Z'.
 *
 * Return: 1 if 'c' is an alphabetic character, 0 otherwise.
 */

int checkAlphabetic(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

