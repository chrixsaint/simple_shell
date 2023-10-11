#include "shell.h"

/**
 * get_node_count - Count the number of nodes in a linked list.
 * @h: Pointer to the first node of the linked list.
 *
 * This function calculates the number of nodes in
 * the given linked list and returns the count.
 *
 * Return: The number of nodes in the linked list.
 */

size_t get_node_count(const list_t *h)
{
	size_t aii = 0;

	for (aii = 0; h; aii++)
	{
		h = h->next;
	}
	return (aii);
}
