#include "shell.h"

/**
 * add_node_to_tail - Adds a node to the end of a linked list.
 * @head: Address of a pointer to the head node.
 * @str: The string to be stored in the new node.
 * @num: Node index used by history (if applicable).
 *
 * This function creates a new node and appends it to the end of the list.
 *
 * Return: A pointer to the newly created node, or NULL on failure.
 */

list_t *add_node_to_tail(list_t **head, const char *str, int num)
{
	list_t *n, *new_head;

	if (head == NULL)
		return (NULL);

	n = *head;
	new_head = malloc(sizeof(list_t));
	if (new_head == NULL)
		return (NULL);
	assign_memory((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = duplicate_strng(str);
		if (new_head->str == NULL)
		{
			free(new_head);
			return (NULL);
		}
	}
	if (n != NULL)
	{
		while (n->next)
			n = n->next;
		n->next = new_head;
	}
	else
	{
		*head = new_head;
	}
	return (new_head);
}
