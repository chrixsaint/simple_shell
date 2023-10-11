#include "shell.h"

/**
 * processEnvironVariable - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 * environ.c
 */
int processEnvironVariable(info_t *info)
{
	print_string_nodes(info->env);
	return (0);
}