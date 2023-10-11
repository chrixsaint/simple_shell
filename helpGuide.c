#include "shell.h"

/**
 * helpGuide - Get a line of input from the
 * user without the newline character.
 * @info: Pointer to the parameter struct.
 *
 * This function reads a line of user input and
 * removes the newline character.
 *
 * Return: The number of bytes read.
 */
int helpGuide(info_t *info)
{
	char **arg_arr;

	arg_arr = info->argv;
	write_string("help call works. Function not yet implemented \n");
	if (0)
	{
		write_string(*arg_arr);
	}
	return (0);
}
