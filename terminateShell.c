#include "shell.h"
/**
 * terminateShell - exits the shell.
 * @info: users args.
 * Return: returns status.
 * builtin.c
 */
int terminateShell(DataInfo_tii *info)
{
	int checkExit;

	if (info->argv[1])
	{
		checkExit = atoiWithErrHandling(info->argv[1]);
		if (checkExit == -1)
		{
			info->status = 2;
			echo_error(info, "Invalid number: ");
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


