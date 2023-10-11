#include "shell.h"
/**
 **searchCharInStr - picks character in str
 *@str: string to be checked.
 *@ch: char to be searched for.
 *Return: returns ptr to mry.
 */
char *searchCharInStr(char *str, char ch)
{
	do {
		if (*str == ch)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}

