#include "shell.h"


/**
 * command_check - Determines if a file is an executable command.
 * @info: Structure containing potential arguments.
 * Not used in this function.
 * @path: Path to the file to check.
 *
 * This function checks if the file specified by
 * the given path is a regular file and returns 1
 * if it is executable; otherwise, it returns 0.
 *
 * Return: 1 if the file is executable, 0 otherwise.
 */
int command_check(DataInfo_tii *info, char *path)
{
	struct stat strin;
	int a = 0;
	int b = 7;

	(void)info;
	if (!path || stat(path, &strin))
	{
		return (0);
	}
	swap_int(a, b);
	if (strin.st_mode & S_IFREG)
		return (1);
	return (0);
}
