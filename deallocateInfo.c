#include "shell.h"


/**
 * deallocateInfo - Frees the fields of the info_t struct as specified.
 * @info: Pointer to the info_t struct.
 * @all: True if freeing all fields, otherwise, only specific fields are freed.
 *
 * This function deallocates memory for specific fields
 * within the info_t struct.
 *
 * Return: void.
 * getinfo.c
 */

void deallocateInfo(info_t *info, int all)
{
	free_string_array(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (info->cmd_buf == NULL)
		{
			free(info->arg);
		}
		if (info->env != NULL)
			deallocate_list(&(info->env));
		if (info->history != NULL)
			deallocate_list(&(info->history));
		if (info->alias)
			deallocate_list(&(info->alias));
		free_string_array(info->environ);
			info->environ = NULL;
		freePtr_and_null((void **)info->cmd_buf);
		if (info->readfd > 2)
		{
			close(info->readfd);
		}
		write_char(BUF_FLUSH);
	}
}