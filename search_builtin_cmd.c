#include "shell.h"
/**
 * search_builtin_cmd - looks for builtin cmds
 * @my_args: users args.
 * Return: returns 0 if success.
 * shell_loop.c
 */
int search_builtin_cmd(DataInfo_tii *my_args)
{
	int idx, cmd_results = -1;
	cmdHandler_table builtintbl[] = {
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

	for (idx = 0; builtintbl[idx].type; idx++)
		if (string_compare(my_args->argv[0], builtintbl[idx].type) == 0)
		{
			my_args->line_count++;
			cmd_results = builtintbl[idx].func(my_args);
			break;
		}
	return (cmd_results);
}


