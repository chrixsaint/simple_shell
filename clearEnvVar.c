#include "shell.h"

/**
 * clearEnvVar - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 * environ.c
 */
int clearEnvVar(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		errorOutput("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		resetEnvVar(info, info->argv[i]);

	return (0);
}


