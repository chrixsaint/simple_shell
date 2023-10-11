#include "shell.h"

/**
 * get_node_count - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 * lists1.c
 */
size_t get_node_count(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}


