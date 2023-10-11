#include "shell.h"
/**
 * replicate_chars -  chars are replicated
 * @pathstr: str PATH.
 * @start: index to begin.
 * @stop: index to stop.
 * Return: returns ptr to str
 * parser.c
 */
char *replicate_chars(char *pathstr, int start, int stop)
{
	int idx = 0;
	int ctr = 0;
	static char buffr[1024];

	for (ctr = 0, idx = start; idx < stop; idx++)
		if (pathstr[idx] != ':')
			buffr[ctr++] = pathstr[idx];
	buffr[ctr] = 0;
	return (buffr);
}


