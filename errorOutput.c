#include "shell.h"

/**
 * errorOutput - Prints an error message to the standard error (stderr).
 * @str: The string to be printed.
 *
 * This function is responsible for writing an error message to
 * the standard error (stderr) output stream.
 *
 * Return: Nothing.
 */

void errorOutput(char *str)
{
	int aii;

	if (str == NULL)
	{
		return;
	}
	for (aii = 0; str[aii] != '\0'; aii++)
		writeErrorChar(str[aii]);
}

