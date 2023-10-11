#include "shell.h"

/**
 * resetAlias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 * builtin1.c
 */
int resetAlias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = searchCharInStr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}
