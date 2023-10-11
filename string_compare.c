#include "shell.h"
/**
 * string_compare - compares 2 strs.
 * @s1: string one
 * @s2: string two
 * Return: returns negative if s1 less than s2, positive if s1 greater s2.
 * string.c
 */
int string_compare(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 < *s2 ? -1 : 1);
	}
}


