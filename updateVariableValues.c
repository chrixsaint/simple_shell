#include "shell.h"


/**
 * updateVariableValues - replaces vars in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 * vars.c
 */
int updateVariableValues(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!string_compare(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
				duplicate_strng(changeNumberBase(info->status, 10, 0)));
			continue;
		}
		if (!string_compare(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
				duplicate_strng(changeNumberBase(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
				duplicate_strng(searchCharInStr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], duplicate_strng(""));

	}
	return (0);
}
