#include "shell.h"

/**
 * populate_env_list - fills env list
 * @info: users arguments.
 * Return: returns 0
 * environ.c
 */
int populate_env_list(DataInfo_tii *info)
{
	size_t idx = 0;
	leest_ti *n = NULL;
	int a = 0, b = 0;

	while (environ[idx])
	{
		add_node_to_tail(&n, environ[idx], 0);
		idx++;
	}
	swap_int(b, a);
	info->env = n;
	return (0);
}

