#include "shell.h"


/**
 *write_string - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 * string1.c
 */
void write_string(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		write_char(str[i]);
		i++;
	}
}
