#include "shell.h"
/**
 * write_char - displays char c.
 * @c: char to disp.
 * Return: returns 1.
 * string1.c
 */
int write_char(char c)
{
	static char buffer[WRITE_BUF_SIZE];
	static int idx;

	if (c == BUF_FLUSH || idx >= WRITE_BUF_SIZE)
	{
		write(1, buffer, idx);
		idx = 0;
	}
	if (c != BUF_FLUSH)
	{
		buffer[idx++] = c;
	}
	return (1);
}

