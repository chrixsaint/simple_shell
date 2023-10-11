#include "shell.h"


/**
 * switchDirectory - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 * builtin.c
 */

int switchDirectory(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		write_string("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = fetchEnvironVariable(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = fetchEnvironVariable(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (string_compare(info->argv[1], "-") == 0)
	{
		if (!fetchEnvironVariable(info, "OLDPWD="))
		{
			write_string(s);
			write_char('\n');
			return (1);
		}
		write_string(fetchEnvironVariable(info, "OLDPWD=")), write_char('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = fetchEnvironVariable(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		echo_error(info, "can't cd to ");
		errorOutput(info->argv[1]), writeErrorChar('\n');
	}
	else
	{
		defineEnvVar(info, "OLDPWD", fetchEnvironVariable(info, "PWD="));
		defineEnvVar(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
