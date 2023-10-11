#include "shell.h"


/**
 * replace_alias - replaces an aliases in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 * vars.c
 */
int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = searchCharInStr(node->str, '=');
		if (!p)
			return (0);
		p = duplicate_strng(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}