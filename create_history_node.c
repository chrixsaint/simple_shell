#include "shell.h"

/**
 * create_history_node - Adds a new entry to a history linked list.
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: The input buffer to be added to the history.
 * @linecount: The history line count, histcount.
 *
 * This function adds a new entry with the provided input buffer
 * `buf` and history line count `linecount`
 * to the history linked list stored in the `info` structure.
 *
 * Return: Always 0.
 */

int create_history_node(info_t *info, char *buf, int linecount)
{
	list_t *nnodde;

	nnodde = NULL;
	if (info->history)
	{
		nnodde = info->history;
	}
	add_node_to_tail(&nnodde, buf, linecount);

	if (info->history == NULL)
	{
		info->history = nnodde;
	}
	return (0);
}
