#include "shell.h"
/**
 *write_string - writes str input
 *@str: str input
 * Return: returns void.
 * string1.c
 */
void write_string(char *str)
{
	int idx = 1;

	if (str == NULL)
	{
		return;
	}
	for (idx = 0; str[idx] != '\0'; idx++)
		write_char(str[idx]);
}


