#include "shell.h"

/**
 * eraseInfo - initializes info_t struct
 * @info: struct address
 * getinfo.c
 */
void eraseInfo(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}


