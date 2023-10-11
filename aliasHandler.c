#include "shell.h"

/**
 * aliasHandler - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 * builtin1.c
 */
int aliasHandler(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			printAliasString(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = searchCharInStr(info->argv[i], '=');
		if (p)
			initializeAlias(info, info->argv[i]);
		else
			printAliasString(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

