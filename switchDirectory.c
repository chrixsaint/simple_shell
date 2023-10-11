#include "shell.h"
/**
 * switchDirectory - converts current pth.
 * @info: users arguments.
 * Return: returns 0.
 * builtin.c
 */

int switchDirectory(info_t *info)
{
	char *str, *pth, bff[1024];
	int dir_result;

	str = getcwd(bff, 1024);
	if (!str)
		write_string("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		pth = fetchEnvironVariable(info, "HOME=");
		if (!pth)
		{
			dir_result = chdir((pth = fetchEnvironVariable(info, "PWD=")) ? pth : "/");
		}	
		else
		{
			dir_result = chdir(pth);
		}
	}
	else if (string_compare(info->argv[1], "-") == 0)
	{
		if (!fetchEnvironVariable(info, "OLDPWD="))
		{
			write_string(str);
			write_char('\n');
			return (1);
		}
		write_string(fetchEnvironVariable(info, "OLDPWD=")), write_char('\n');
		dir_result = chdir((pth = fetchEnvironVariable(info, "OLDPWD=")) ? pth : "/");
	}
	else
	{
		dir_result = chdir(info->argv[1]);
	}
	if (dir_result == -1)
	{
		echo_error(info, "can not change directory to given path ");
		errorOutput(info->argv[1]), writeErrorChar('\n');
	}
	else
	{
		defineEnvVar(info, "OLDPWD", fetchEnvironVariable(info, "PWD="));
		defineEnvVar(info, "PWD", getcwd(bff, 1024));
	}
	return (0);
}


