#include "shell.h"
/**
 * stringlength -  gets length of given str
 * @s: str with the sought len.
 * Return: returns len of str
 * string.c
 */
int stringlength(char *s)
{
	int idx = 0;

	if (!s)
		return (0);

	while (*s++)
	{
		idx++;
	}
	return (idx);
}


