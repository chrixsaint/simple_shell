#include "shell.h"


/**
 * atoiWithErrHandling - Converts a string to an
 * integer with error handling.
 * @s: The string to be converted.
 *
 * This function attempts to convert the given string 's' to an
 * integer. If successful, it returns the converted integer
 * If the string contains non-numeric characters or the outcome
 * is out of the range of `int`, it returns -1 to indicate an error.
 *
 * Return: The converted integer if successful, -1 on error.
 */

int atoiWithErrHandling(char *s)
{
	unsigned long int outcome = 0;
	int q;

	q = 0;
	if (*s == '+')
	{
		s++;
	}
	while (s[q] != '\0')
	{
		if (s[q] >= '0' && s[q] <= '9')
		{
			outcome *= 10;
			outcome += (s[q] - '0');
			if (outcome > INT_MAX)
				return (-1);
		}
		else
		{
			return (-1);
		}
		q++;
	}
	return (outcome);
}


