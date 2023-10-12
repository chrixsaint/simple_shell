#include "shell.h"


/**
 * lookup_cmd - Find and execute a command in the PATH.
 * @info: The parameter & return info struct.
 *
 * This function attempts to locate and execute a command specified in
 * the argument vector within the directories listed in the
 * PATH environment variable.
 *
 * Return: void.
 */
void lookup_cmd(DataInfo_tii *info)
{
	int aii, kaii;
	char *path;

	path = NULL;
	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (aii = 0, kaii = 0; info->arg[aii]; aii++)
		if (!delimiterCheck(info->arg[aii], " \t\n"))
		{
			kaii++;
		}
	if (!kaii)
	{
		return;
	}

	path = get_path(info, fetchEnvironVariable(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		execute_command(info);
	}
	else
	{
		if ((interactive(info) || fetchEnvironVariable(info, "PATH=")
			|| info->argv[0][0] == '/') && command_check(info, info->argv[0]))
			execute_command(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			echo_error(info, "not found\n");
		}
	}
}


