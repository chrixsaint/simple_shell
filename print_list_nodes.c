#include "shell.h"
/**
 * print_list_nodes - writes elements of list
 * @h: ptr to start node
 * Return: returns sizeof list
 * lists1.c
 */
size_t print_list_nodes(const leest_ti *h)
{
	size_t idx;

	idx = 0;
	while (h)
	{
		write_string(changeNumberBase(h->num, 10, 0));
		write_char(':');
		write_char(' ');
		write_string(h->str ? h->str : "(nil)");
		write_string("\n");
		h = h->next;
		idx++;
	}
	return (idx);
}


