#include "shell.h"


/**
 * aliasHandler - Handles alias commands to mimic
 * the behavior of the alias builtin (man alias).
 * @info: Structure containing potential arguments.
 * Used to maintain a consistent function prototype.
 *
 * This function handles alias commands, allowing users to
 * view, set, or modify aliases.
 * If called with no arguments, it displays all existing aliases.
 * If called with arguments in the form of 'alias name=value',
 * it creates or modifies an alias.
 * If called with an alias name, it displays the alias value
 *
 * Return: Always 0
 */
int aliasHandler(DataInfo_tii *info)
{
	leest_ti *n = NULL;
	int q = 0;
	int a = 0;
	int b = 7;
	char *r = NULL;

	q = 1;
	if (info->argc == 1)
	{
		n = info->alias;
		while (n)
		{
			printAliasString(n);
			n = n->next;
		}
		return (0);
	}
	swap_int(a, b);
	while (info->argv[q])
	{
		r = searchCharInStr(info->argv[q], '=');
		if (r != NULL)
		{
			initializeAlias(info, info->argv[q]);
		}
		else
			printAliasString(node_starts_with(info->alias, info->argv[q], '='));
		q++;
	}

	return (0);
}

