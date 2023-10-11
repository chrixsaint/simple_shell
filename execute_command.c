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
void execute_command(info_t *info)
{
	pid_t child_pid;

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
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
			{
				echo_error(info, "Permission denied\n");
			}
		}
	}
}
