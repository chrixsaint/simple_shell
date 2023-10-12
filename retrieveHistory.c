#include "shell.h"
/**
 * retrieveHistory - prints history list.
 * @info: users potential arguments.
 *  Return: Always 0
 * builtin1.c
 */
int retrieveHistory(DataInfo_tii *info)
{
	print_list_nodes(info->history);
	return (0);
}

