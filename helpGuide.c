#include "shell.h"

/**
 * helpGuide - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 * builtin.c
 */
int helpGuide(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	write_string("help call works. Function not yet implemented \n");
	if (0)
		write_string(*arg_array); /* temp att_unused workaround */
	return (0);
}

