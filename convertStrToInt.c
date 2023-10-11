#include "shell.h"

/**
 * convertStrToInt - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * This function takes a string `s` and attempts to convert it into an integer.
 * It handles positive and negative integers.
 *
 * Return: The converted integer if successful, or 0
 * if no valid number is found.
 */
int convertStrToInt(char *s)
{
	unsigned int outcome;
	int aii, siine;
	int flarrg, display;

	siine = 1, aii = 0;
	outcome = 0;
	flarrg = 0;

	while (s[aii] != '\0' && flarrg != 2)
	{
		if (s[aii] == '-')
			siine *= -1;

		if (s[aii] >= '0' && s[aii] <= '9')
		{
			flarrg = 1;
			outcome *= 10;
			outcome += (s[aii] - '0');
		}
		else if (flarrg == 1)
			flarrg = 2;
		aii++;
	}

	if (siine == -1)
	{
		display = -outcome;
	}
	else
		display = outcome;

	return (display);
}
