#include "shell.h"


/**
 * renumber_history - reenumerates linked list.
 * @info: users arguments.
 * Return: returns new hist count
 * history.c
 */
int renumber_history(info_t *info)
{
	int idx = 0;
	list_t *n;
	
	n = info->history;
	while (n)
	{
		n->num = idx++;
		n = n->next;
	}
	return (info->histcount = idx);
}

