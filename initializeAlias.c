#include "shell.h"

/**
 * initializeAlias - Sets an alias to a given string.
 * @info: Structure containing potential arguments.
 * @str: The string alias in the format "alias_name=alias_value".
 *
 * This function initializes an alias in the shell by parsing
 * the input string and adding it to the alias list.
 *
 * Return: 0 on success, 1 on error.
 */

int initializeAlias(info_t *info, char *str)
{
	char *ptr;

	ptr = searchCharInStr(str, '=');
	if (ptr == NULL)
	{
		return (1);
	}
	if (!*++ptr)
	{
		return (resetAlias(info, str));
	}

	resetAlias(info, str);
	return (add_node_to_tail(&(info->alias), str, 0) == NULL);
}


