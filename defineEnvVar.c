#include "shell.h"


/**
 * defineEnvVar - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 * getenv.c
 */
int defineEnvVar(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(stringlength(var) + stringlength(value) + 2);
	if (!buf)
		return (1);
	copy_str(buf, var);
	merge_strings(buf, "=");
	merge_strings(buf, value);
	node = info->env;
	while (node)
	{
		p = prefix_match(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_to_tail(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}

