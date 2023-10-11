#include "shell.h"


/**
 *outputStrToFD - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int outputStrToFD(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += outputCharToFD(*str++, fd);
	}
	return (i);
}