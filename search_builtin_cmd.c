#include "shell.h"


/**
 * search_builtin_cmd - finds a builtin command
 * @info: the parameter & return info struct
 *
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 * shell_loop.c
 */
int search_builtin_cmd(info_t *info)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", terminateShell},
		{"env", processEnvironVariable},
		{"help", helpGuide},
		{"history", retrieveHistory},
		{"setenv", modifyEnvVar},
		{"unsetenv", clearEnvVar},
		{"cd", switchDirectory},
		{"alias", aliasHandler},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (string_compare(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	return (built_in_ret);
}
