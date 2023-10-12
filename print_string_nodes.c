#include "shell.h"
/**
 * print_string_nodes - outputs str member of list
 * @hd: pointer to starting node
 * Return: returns sizeof ls
 * lists.c
 */size_t print_string_nodes(const leest_ti *hd)
{
	size_t idx;

	for (idx = 0; hd; idx++)
	{
		write_string(hd->str ? hd->str : "nill");
		write_string("\n");
		hd = hd->next;
	}
	return (idx);
}


