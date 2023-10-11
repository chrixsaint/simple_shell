#include "shell.h"


/**
 * print_string_nodes - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 * lists.c
 */
size_t print_string_nodes(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		write_string(h->str ? h->str : "(nil)");
		write_string("\n");
		h = h->next;
		i++;
	}
	return (i);
}
