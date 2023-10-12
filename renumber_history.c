#include "shell.h"


/**
 * renumber_history - reenumerates linked list.
 * @info: users arguments.
 * Return: returns new hist count
 * history.c
 */
int renumber_history(DataInfo_tii *info)
{
	int idx = 0;
	leest_ti *n;
	
	n = info->history;
	while (n)
	{
		n->num = idx++;
		n = n->next;
	}
	return (info->histcount = idx);
}

