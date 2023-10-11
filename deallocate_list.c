#include "shell.h"


/**
 * deallocate_list - Frees all nodes of a linked
 * list and sets the list head to NULL.
 * @head_ptr: Address of the pointer to the head node.
 *
 * This function deallocates memory for all nodes in a linked list
 * starting from the head node
 * and sets the head pointer to NULL, to effectively
 * clear the linked list.
 *
 * Return: void.
 */

void deallocate_list(list_t **head_ptr)
{
	list_t *nnodde;
	list_t *other_nnodde, *head;

	if (head_ptr == NULL || *head_ptr == NULL)
	{
		return;
	}
	head = *head_ptr;
	nnodde = head;
	while (nnodde)
	{
		other_nnodde = nnodde->next;
		free(nnodde->str);
		free(nnodde);
		nnodde = other_nnodde;
	}
	*head_ptr = NULL;
}
