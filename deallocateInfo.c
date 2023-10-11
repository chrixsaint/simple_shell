#include "shell.h"


/**
 * deallocateInfo - frees info_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 * getinfo.c
 */
void deallocateInfo(info_t *info, int all)
{
	free_string_array(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			deallocate_list(&(info->env));
		if (info->history)
			deallocate_list(&(info->history));
		if (info->alias)
			deallocate_list(&(info->alias));
		free_string_array(info->environ);
			info->environ = NULL;
		freePtr_and_null((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		write_char(BUF_FLUSH);
	}
}