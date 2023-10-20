#include "shell.h"
/**
 * modifyEnvVar - creates an instance of new environment var.
 * @my_args: users input arguments.
 *  Return: returns 0.
 * environ.c
 */
int modifyEnvVar(DataInfo_tii *my_args)
{
	if (my_args->argc != 3)
	{
		errorOutput("Incorrect number of arguements\n");
		return (1);
	}
	if (defineEnvVar(my_args, my_args->argv[1], my_args->argv[2]))
	{
		return (0);
	}
	return (1);
}


