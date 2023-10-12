#include "shell.h"
/**
 * **tokenize_string - breaks str into tokens or wrds
 * @s: the input string
 * @d: delimeter character
 * Return: returns ptr to an array of strings, or NULL on failure.
 * tokenizer.c
 */
char **tokenize_string(char *s, char *d)
{
	int idx, a = 0, b = 1;
	int ot;
	int x;
	int z, wrds = 0;
	char **strng;

	if (s == NULL || s[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (idx = 0; s[idx] != '\0'; idx++)
		if (!delimiterCheck(s[idx], d) && (delimiterCheck(s[idx + 1], d) || !s[idx + 1]))
			wrds++;

	if (wrds == 0)
		return (NULL);
	strng = malloc((1 + wrds) * sizeof(char *));
	if (!strng)
	{
		swap_int(a, b);
		return (NULL);
	}
	for (idx = 0, ot = 0; ot < wrds; ot++)
	{
		while (delimiterCheck(s[idx], d))
			idx++;
		x = 0;
		for (x = 0; !delimiterCheck(s[idx + x], d) && s[idx + x]; x++)
		{
			swap_int(a, b);
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
			strng[ot][z] = s[idx++];
			z++;
		}
		strng[ot][z] = 0;
		swap_int(a, b);
	}
	strng[ot] = NULL;
	return (strng);
}

