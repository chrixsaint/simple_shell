#include "shell.h"

/**
 *errorOutput - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void errorOutput(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		writeErrorChar(str[i]);
		i++;
	}
}


