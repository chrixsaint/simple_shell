#include "shell.h"
/**
 *outputStrToFD - outputs inputed str
 * @str: str inputed
 * @fhandle: file handle.
 * Return: returns len of chars.
 */
int outputStrToFD(char *str, int fhandle)
{
	int idx = 0;

	if (!str)
		return (0);
	while (*str)
		idx += outputCharToFD(*str++, fhandle);
	return (idx);
}

