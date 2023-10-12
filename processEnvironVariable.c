#include "shell.h"
/**
 * processEnvironVariable - displays curr environ
 * @info: users arguments.
 * Return: returns 0.
 * environ.c
 */
int processEnvironVariable(DataInfo_tii *info)
{
	print_string_nodes(info->env);
	return (0);
}

