#include "shell.h"

/**
 * populate_env_list - fills env list
 * @info: users arguments.
 * Return: returns 0
 * environ.c
 */
int populate_env_list(info_t *info)
{
	size_t idx = 0;
	list_t *n = NULL;

	while (environ[idx])
	{
		add_node_to_tail(&n, environ[idx], 0);
		idx++;
	}
	info->env = n;
	return (0);
}

