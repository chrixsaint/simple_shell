#include "shell.h"


/**
 * get_node_index - Get the index of a node in a linked list.
 * @head: Pointer to the head of the linked list.
 * @node: Pointer to the node for which you want to find the index.
 *
 * This function searches for the given node in the
 * linked list and returns its index.
 *
 * Return: The index of the node if found, or
 * -1 if the node is not in the list.
 */

ssize_t get_node_index(leest_ti *head, leest_ti *node)
{
	size_t aii = 0;

	for (aii = 0; head; aii++)
	{
		if (head == node)
		{
			return (aii);
		}
		head = head->next;
	}
	return (-1);
}
