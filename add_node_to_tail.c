#include "shell.h"

/**
 * add_node_to_tail - Adds a node to the end of a linked list.
 * @head: Address of a pointer to the head node
 * @str: The string to be stored in the new node.
 * @num: Node index used by history (if applicable).
 *
 * This function creates a new node and appends it to the end of the list.
 *
 * Return: A pointer to the newly created node, or NULL on failure.
 */

leest_ti *add_node_to_tail(leest_ti **head, const char *str, int num)
{
	leest_ti *n, *new_head;
	int x = 0;
	int y = 0;

	if (head == NULL)
		return (NULL);

	n = *head;
	new_head = malloc(sizeof(leest_ti));
	if (new_head == NULL)
		return (NULL);
	assign_memory((void *)new_head, 0, sizeof(leest_ti));
	new_head->num = num;
	if (str)
	{
		new_head->str = duplicate_strng(str);
		if (new_head->str == NULL)
		{
			swap_int(x, y);
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


