#include "shell.h"


/**
 * execute_command - Forks a child process to run the specified command.
 * @info: The parameter struct containing command and execution information.
 *
 * This function is responsible for forking a child process and
 * executing a command in that child process using `execve`.
 * The command's path, arguments, and environment are set up using
 * the information stored in the `info` struct.
 *
 * Return: void.
 */
void execute_command(DataInfo_tii *info)
{
	pid_t child_pid;
	char *s = "";

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			print_rev(s);
			deallocateInfo(info, 1);
			if (errno == EACCES)
			{
				exit(126);
			}
			exit(1);
		}
	}
	else
	{
		print_rev(s);
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
			{
				print_rev(s);
				echo_error(info, "Permission denied\n");
			}
		}
	}
}

