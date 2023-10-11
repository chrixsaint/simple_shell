#include "shell.h"


/**
 * duplicate_strng - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 * string1.c
 */
char *duplicate_strng(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}


