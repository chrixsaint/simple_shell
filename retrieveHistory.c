#include "shell.h"

/**
 * retrieveHistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 * builtin1.c
 */
int retrieveHistory(info_t *info)
{
	print_list_nodes(info->history);
	return (0);
}