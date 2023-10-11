#include "shell.h"

/**
 * copy_str - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 * string1.c
 */
char *copy_str(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
