#include "shell.h"

/**
 * fetchEnvironVariable - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 * environ.c
 */
char *fetchEnvironVariable(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = prefix_match(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

