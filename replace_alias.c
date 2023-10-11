#include "shell.h"
/**
 * replace_alias - changes aliases from the tokenized str.
 * @info: users args.
 * Return: returns 1 if replaced.
 * vars.c
 */
int replace_alias(info_t *info)
{
	list_t *n;
	int idx = 0;
	char *ptr;

	while (idx < 10)
	{
		n = node_starts_with(info->alias, info->argv[0], '=');
		if (!n)
		{
			return (0);
		}
		free(info->argv[0]);
		ptr = searchCharInStr(n->str, '=');
		if (!ptr)
			return (0);
		ptr = duplicate_strng(ptr + 1);
		if (!ptr)
		{
			return (0);
		}
		info->argv[0] = ptr;
		idx++;
	}
	return (1);
}

