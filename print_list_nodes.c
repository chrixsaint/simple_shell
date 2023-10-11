#include "shell.h"


/**
 * print_list_nodes - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 * lists1.c
 */
size_t print_list_nodes(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		write_string(changeNumberBase(h->num, 10, 0));
		write_char(':');
		write_char(' ');
		write_string(h->str ? h->str : "(nil)");
		write_string("\n");
		h = h->next;
		i++;
	}
	return (i);
}
