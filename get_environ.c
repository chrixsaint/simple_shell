#include "shell.h"

/**
 * get_environ - Returns a string array copy
 * of the environment variables.
 * @info: The parameter struct containing potential arguments.
 *
 * This function retrieves the environment variables stored in
 * the parameter struct and returns a copy of them as a string array.
 *
 * Return: A string array containing environment variable strings.
 */

char **get_environ(DataInfo_tii *info)
{
	if (info->environ == NULL || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}


