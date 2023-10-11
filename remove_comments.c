#include "shell.h"
/**
 * remove_comments - this replaces 1st occurence of '#' with null char
 * @buffer: ptr to string being modified
 * Return: returns 0.
 */
void remove_comments(char *buffer)
{
	int idx = 0;

	while (buffer[idx] != '\0')
	{
		if (buffer[idx] == '#' && (!idx || buffer[idx - 1] == ' '))
		{
			buffer[idx] = '\0';
			break;
		}
		idx++;
	}
}

