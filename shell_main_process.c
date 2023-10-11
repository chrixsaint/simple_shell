#include "shell.h"

/**
 * shell_main_process - main shell loop
 * @info: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 * shell_loop.c
 */
int shell_main_process(info_t *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		eraseInfo(info);
		if (interactive(info))
			write_string("Chrix_Godwin$ ");
		writeErrorChar(BUF_FLUSH);
		r = getUserCommand(info);
		if (r != -1)
		{
			defineInfo(info, av);
			builtin_ret = search_builtin_cmd(info);
			if (builtin_ret == -1)
				lookup_cmd(info);
		}
		else if (interactive(info))
			write_char('\n');
		deallocateInfo(info, 0);
	}
	write_history(info);
	deallocateInfo(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}
