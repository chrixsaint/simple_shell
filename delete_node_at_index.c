#include "shell.h"


/**
 * delete_node_at_index - Deletes a node at a specified index in a linked list.
 * @head: Address of a pointer to the first node in the list.
 * @index: The index of the node to be deleted (0-based).
 *
 * This function removes a node from a linked list at the specified index.
 *
 * Return: 1 on success, 0 on failure (e.g., if the index is out of bounds).
 * lists.c
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	unsigned int aii;
	list_t *nnodde, *prev_node;


	if (head == NULL || *head == NULL)
	{
		return (0);
	}

	if (!index)
	{
		nnodde = *head;
		*head = (*head)->next;
		free(nnodde->str);
		free(nnodde);
		return (1);
	}
	nnodde = *head;
	for (aii = 0; nnodde; aii++)
	{
		if (aii == index)
		{
			prev_node->next = nnodde->next;
			free(nnodde->str);
			free(nnodde);
			return (1);
		}
		prev_node = nnodde;
		nnodde = nnodde->next;
	}
	return (0);
}
