#include "shell.h"

/**
 * clearEnvVar - Remove one or more environment variables.
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 *
 * This function removes one or more environment variables
 * specified as arguments.
 * If no arguments are provided, it displays an error message.
 *
 * Return: 0 on success, 1 on error.
 */
int clearEnvVar(info_t *info)
{
	int q;

	q = 1;
	if (info->argc == 1)
	{
		errorOutput("Too few arguements.\n");
		return (1);
	}
	while (q <= info->argc)
	{
		resetEnvVar(info, info->argv[q]);
		q++;
	}

	return (0);
}


