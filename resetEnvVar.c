#include "shell.h"
/**
 * resetEnvVar - Remove an environment variable
 * @info: users potential arguments.
 * @field: env field field.
 *  Return: returns 1 on delet.
 * getenv.c
 */
int resetEnvVar(DataInfo_tii *info, char *field)
{
	size_t idx = 0;
	leest_ti *n;
	char *p;

	n = info->env;
	if (!n || !field)
		return (0);

	while (n)
	{
		p = prefix_match(n->str, field);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), idx);
			idx = 0;
			n = info->env;
			continue;
		}
		n = n->next;
		idx++;
	}
	return (info->env_changed);
}


