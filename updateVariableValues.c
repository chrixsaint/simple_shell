#include "shell.h"
/**
 * updateVariableValues - vars are replaced from tokenized string
 * @info: users input args.
 * Return: returns 1.
 * vars.c
 */
int updateVariableValues(info_t *info)
{
	list_t *n;
	int idx;

	for (idx = 0; info->argv[idx]; idx++)
	{
		if (info->argv[idx][0] != '$' || !info->argv[idx][1])
			continue;

		if (!string_compare(info->argv[idx], "$?"))
		{
			replace_string(&(info->argv[idx]),
				duplicate_strng(changeNumberBase(info->status, 10, 0)));
			continue;
		}
		if (!string_compare(info->argv[idx], "$$"))
		{
			replace_string(&(info->argv[idx]),
				duplicate_strng(changeNumberBase(getpid(), 10, 0)));
			continue;
		}
		n = node_starts_with(info->env, &info->argv[idx][1], '=');
		if (n != NULL)
		{
			replace_string(&(info->argv[idx]),
				duplicate_strng(searchCharInStr(n->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[idx], duplicate_strng(""));
	}
	return (0);
}


