#include "shell.h"

/**
 * interactive - Determines if the shell is
 * running in interactive mode.
 * @info: Structure containing potential arguments.
 * Used to maintain constant function prototype.
 *
 * This function checks if the shell is running
 * in interactive mode by examining whether it is attached
 * to a terminal on the standard input (file descriptor 0).
 *
 * Return: 1 if in interactive mode, 0 otherwise.
 */
int interactive(DataInfo_tii *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

