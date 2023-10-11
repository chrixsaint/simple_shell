#include "shell.h"
/**
 * **tokenize_string - breaks str into tokens or wrds
 * @str: the input string
 * @d: delimeter character
 * Return: returns ptr to an array of strings, or NULL on failure
 * tokenizer.c
 */

char **tokenize_string(char *str, char *d)
{
	int idx;
	int ot;
	int x;
	int z, wrds = 0;
	char **strng;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (idx = 0; str[idx] != '\0'; idx++)
		if (!delimiterCheck(str[idx], d) && (delimiterCheck(str[idx + 1], d) || !str[idx + 1]))
			wrds++;

	if (wrds == 0)
		return (NULL);
	strng = malloc((1 + wrds) * sizeof(char *));
	if (!strng)
	{
		return (NULL);
	}
	for (idx = 0, ot = 0; ot < wrds; ot++)
	{
		while (delimiterCheck(str[idx], d))
			idx++;
		x = 0;
		for (x = 0; !delimiterCheck(str[idx + x], d) && str[idx + x]; x++)
		{
			;
		}
		strng[ot] = malloc((x + 1) * sizeof(char));
		if (!strng[ot])
		{
			x  = 0;
			while (x < ot)
			{
				free(strng[x]);
				x++;
			}
			free(strng);
			return (NULL);
		}
		z = 0;
		while (z < x)
		{
			strng[ot][z] = str[idx++];
			z++;
		}
		strng[ot][z] = 0;
	}
	strng[ot] = NULL;
	return (strng);
}

