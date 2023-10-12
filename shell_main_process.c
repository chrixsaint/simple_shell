#include "shell.h"
/**
 * shell_main_process - Entry main shell loop
 * @my_args: users args.
 * @my_arg_v: argument list
 * Return: returns 0.
 * shell_loop.c
 */
int shell_main_process(info_t *my_args, char **my_arg_v)
{
	int sys_cmd = 0;
	ssize_t d = 0;
	char *str = "";
	int a = 0;
	int b = 1;

	while (d != -1 && sys_cmd != -2)
	{
		eraseInfo(my_args);
		if (interactive(my_args))
			write_string("Chrix_Godwin$ ");
		writeErrorChar(BUF_FLUSH);
		d = getUserCommand(my_args);
		if (d != -1)
		{
			defineInfo(my_args, my_arg_v);
			sys_cmd = search_builtin_cmd(my_args);
			if (sys_cmd == -1)
			{
				swap_int(a, b);
				lookup_cmd(my_args);
			}
		}
		else if (interactive(my_args))
		{
			swap_int(a, b);
			write_char('\n');
		}
		deallocateInfo(my_args, 0);
	}
	write_history(my_args);
	deallocateInfo(my_args, 1);
	if (!interactive(my_args) && my_args->status)
	{
		swap_int(a, b);
		exit(my_args->status);
	}
	if (sys_cmd == -2)
	{
		prints_half(str);
		if (my_args->err_num == -1)
			exit(my_args->status);
		exit(my_args->err_num);
	}
	return (sys_cmd);
}


