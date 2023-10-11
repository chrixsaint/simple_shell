#include "shell.h"


/**
 * initializeAlias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 * builtin1.c
 */
int initializeAlias(info_t *info, char *str)
{
	char *p;

	p = searchCharInStr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (resetAlias(info, str));

	resetAlias(info, str);
	return (add_node_to_tail(&(info->alias), str, 0) == NULL);
}


