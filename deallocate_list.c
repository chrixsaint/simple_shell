#include "shell.h"


/**
 * deallocate_list - frees all nodes of a list
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 * lists.c
 */
void deallocate_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}

