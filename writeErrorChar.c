#include "shell.h"
/**
 * writeErrorChar - writes error character
 * @c: Char to be printed.
 * Return: returns 1 always
 */
int writeErrorChar(char c)
{
	static char buffer[WRITE_BUF_SIZE];
	static int idx;
	int a = 0;
	int b = 1;

	if (c == BUF_FLUSH || idx >= WRITE_BUF_SIZE)
	{
		write(2, buffer, idx);
		idx = 0;
	}
	if (c != BUF_FLUSH)
	{
		buffer[idx++] = c;
		swap_int(a, b);
	}
	return (1);
}

