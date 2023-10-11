#include "shell.h"

/**
 * terminateShell - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 * builtin.c
 */
int terminateShell(info_t *info)
{
	int exitcheck;

	if (info->argv[1])  /* If there is an exit arguement */
	{
		exitcheck = atoiWithErrHandling(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			echo_error(info, "Illegal number: ");
			errorOutput(info->argv[1]);
			writeErrorChar('\n');
			return (1);
		}
		info->err_num = atoiWithErrHandling(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
