#include "shell.h"
/**
 * writeDecimal - writes dec number
 * @input: number input
 * @fd: file handle
 * Return: returns the num.
 */
int writeDecimal(int input, int fd)
{
	int idx;
	int c = 0;
	int (*prt)(char);
	size_t a;
	size_t curr;

	prt = write_char;
	if (fd == STDERR_FILENO)
	{
		prt = writeErrorChar;
	}
	if (input < 0)
	{
		a = -input;
		prt('-');
		c++;
	}
	else
	{
		a = input;
	}
	curr = a;
	for (idx = 1000000000; idx > 1; idx /= 10)
	{
		if (a / idx)
		{
			prt('0' + curr / idx);
			c++;
		}
		curr %= idx;
	}
	c++;
	prt('0' + curr);
	return (c);
}

