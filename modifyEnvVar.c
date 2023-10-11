#include "shell.h"

/**
 * modifyEnvVar - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 * environ.c
 */
int modifyEnvVar(info_t *info)
{
	if (info->argc != 3)
	{
		errorOutput("Incorrect number of arguements\n");
		return (1);
	}
	if (defineEnvVar(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}


