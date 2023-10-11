#include "shell.h"


/**
 * lookup_cmd - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 * shell_loop.c
 */
void lookup_cmd(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!delimiterCheck(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

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


