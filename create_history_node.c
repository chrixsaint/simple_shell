#include "shell.h"


/**
 * create_history_node - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 * history.c
 */
int create_history_node(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_to_tail(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}
