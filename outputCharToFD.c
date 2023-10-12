#include "shell.h"
/**
 * outputCharToFD - writes char file
 * @ch: character to be printed
 * @fhandle: file handle.
 * Return: returns 1.
 */
int outputCharToFD(char ch, int fhandle)
{
	static char buffer[WRITE_BUF_SIZE];
	static int idx;

	if (ch == BUF_FLUSH || idx >= WRITE_BUF_SIZE)
	{
		write(fhandle, buffer, idx);
		idx = 0;
	}
	if (ch != BUF_FLUSH)
	{
		buffer[idx++] = ch;
	}
	return (1);
}


