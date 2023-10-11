#include "shell.h"
/**
 * **tokenize_string_v2 - breaks str into strings.
 * @str: input chars
 * @d: delimeter char
 * Return: returns ptr to array.
 * tokenizer.c
 */
char **tokenize_string_v2(char *str, char d)
{
	int idx;
	int x;
	int b;
	int ot, wrds = 0;
	char **strng;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (idx = 0; str[idx] != '\0'; idx++)
		if ((str[idx] != d && str[idx + 1] == d) ||
		    (str[idx] != d && !str[idx + 1]) || str[idx + 1] == d)
			wrds++;
	if (wrds == 0)
		return (NULL);
	strng = malloc((1 + wrds) * sizeof(char *));
	if (!strng)
		return (NULL);
	for (idx = 0, x = 0; x < wrds; x++)
	{
		while (str[idx] == d && str[idx] != d)
			idx++;
		for (b = 0; str[idx + b] != d && str[idx + b] && str[idx + b] != d; b++)
			;
		strng[x] = malloc((b + 1) * sizeof(char));
		if (!strng[x])
		{
			b = 0;
			while (b < x)
			{
				free(strng[b]);
				b++;
			}	
			free(strng);
			return (NULL);
		}
		ot = 0;
		while (ot < b)
		{
			strng[x][ot] = str[idx++];
			ot++;
		}
		strng[x][ot] = 0;
	}
	strng[x] = NULL;
	return (strng);
}

