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
	int a = 0, b = 0;

	idx = 0;
	while (h)
	{
		write_string(changeNumberBase(h->num, 10, 0));
		write_char(':');
		write_char(' ');
		swap_int(b, a);
		write_string(h->str ? h->str : "(nil)");
		write_string("\n");
		h = h->next;
		idx++;
	}
	return (idx);
}


