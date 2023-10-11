#include "shell.h"

/**
 * printAliasString - displays alias str
 * @node: alias node
 * Return: returns 0.
 * builtin1.c
 */
int printAliasString(list_t *node)
{
	char *pt = NULL;
	char *zend = NULL;

	if (node)
	{
		pt = searchCharInStr(node->str, '=');
		zend = node->str;
		while (zend <= pt)
		{
			write_char(*zend);
			zend++;
		}
		write_char('\'');
		write_string(pt + 1);
		write_string("'\n");
		return (0);
	}
	return (1);
}


