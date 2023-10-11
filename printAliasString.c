#include "shell.h"

/**
 * printAliasString - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 * builtin1.c
 */
int printAliasString(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = searchCharInStr(node->str, '=');
		for (a = node->str; a <= p; a++)
			write_char(*a);
		write_char('\'');
		write_string(p + 1);
		write_string("'\n");
		return (0);
	}
	return (1);
}


