#include "shell.h"
/**
 * shell_main_process - Entry main shell loop
 * @info: users args.
 * @av: argument list
 * Return: returns 0.
 * shell_loop.c
 */
int shell_main_process(info_t *info, char **av)
{
	int sys_cmd = 0;
	ssize_t d = 0;

	while (d != -1 && sys_cmd != -2)
	{
		eraseInfo(info);
		if (interactive(info))
			write_string("Chrix_Godwin$ ");
		writeErrorChar(BUF_FLUSH);
		d = getUserCommand(info);
		if (d != -1)
		{
			defineInfo(info, av);
			sys_cmd = search_builtin_cmd(info);
			if (sys_cmd == -1)
			{
				lookup_cmd(info);
			}
		}
		else if (interactive(info))
		{
			write_char('\n');
		}
		deallocateInfo(info, 0);
	}
	write_history(info);
	deallocateInfo(info, 1);
	if (!interactive(info) && info->status)
	{
		exit(info->status);
	}
	if (sys_cmd == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (sys_cmd);
}


