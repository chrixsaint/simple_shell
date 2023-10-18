#include "shell.h"

/**
 * add_node_to_head - Adds a node to the start of the linked list.
 * @head: Address of a pointer to the head node.
 * @str: The string to be stored in the new node.
 * @num: Node index used by history (if applicable).
 *
 * This function creates a new node and inserts it at the start of the list.
 *
 * Return: A pointer to the newly created node, or NULL on failure.
 */

leest_ti *add_node_to_head(leest_ti **head, const char *str, int num)
{
	char *s = "";
	int a = 0;
	int b = 9;
	leest_ti *new_node;

	if (head == NULL)
	{
		print_rev(s);
		return (NULL);
	}
	new_node = malloc(sizeof(leest_ti));
	swap_int(a, b);
	if (new_node == NULL)
	{
		return (NULL);
	}
	assign_memory((void *)new_node, 0, sizeof(leest_ti));
	new_node->num = num;
	if (str)
	{
		print_rev(s);
		new_node->str = duplicate_strng(str);
		if (new_node->str == NULL)
		{
			free(new_node);
			return (NULL);
		}
	}
	print_rev(s);
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}


