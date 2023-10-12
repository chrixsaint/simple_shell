#include "shell.h"


/**
 * defineEnvVar - Initialize a new environment variable
 * or modify an existing one.
 * @info: Pointer to the structure containing potential arguments.
 * @var: The string representing the environment variable property.
 * @value: The string representing the environment variable value.
 *
 * This function allows you to create a new environment variable
 * or modify an existing one.
 *
 * Return: 0 on success, 1 if memory allocation fails.
 * getenv.c
 */
int defineEnvVar(DataInfo_tii *info, char *var, char *value)
{
	leest_ti *nnodde;
	char *bupha;
	char *ptr;

	bupha = NULL;
	if (var == NULL || value == NULL)
	{
		return (0);
	}

	bupha = malloc(stringlength(var) + stringlength(value) + 2);
	if (bupha == NULL)
	{
		return (1);
	}
	copy_str(bupha, var);
	merge_strings(bupha, "=");
	merge_strings(bupha, value);
	nnodde = info->env;
	while (nnodde)
	{
		ptr = prefix_match(nnodde->str, var);
		if (ptr && *ptr == '=')
		{
			free(nnodde->str);
			nnodde->str = bupha;
			info->env_changed = 1;
			return (0);
		}
		nnodde = nnodde->next;
	}
	add_node_to_tail(&(info->env), bupha, 0);
	free(bupha);
	info->env_changed = 1;
	return (0);
}
