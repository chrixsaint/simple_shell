#include "shell.h"



/**
 * list_to_strings - Converts a linked list of strings
 * to an array of strings.
 * @head: Pointer to the first node of the linked list.
 *
 * This function takes a linked list of strings and
 * converts it into an array of strings, with the last
 * element in the array set to NULL to indicate the end.
 *
 * Return: A dynamically allocated array of strings, or
 * NULL if memory allocation fails.
 */

char **list_to_strings(leest_ti *head)
{
	char **strn;
	char *str;
	leest_ti *nnodde;
	size_t aii, jaii;

	aii = get_node_count(head);
	nnodde = head;
	jaii = 0;
	if (head == NULL || !aii)
		return (NULL);
	strn = malloc(sizeof(char *) * (aii + 1));
	if (strn == NULL)
	{
		return (NULL);
	}
	for (aii = 0; nnodde; nnodde = nnodde->next, aii++)
	{
		str = malloc(stringlength(nnodde->str) + 1);
		if (str == NULL)
		{
			while (jaii < aii)
			{
				free(strn[jaii]);
				jaii++;
			}
			free(strn);
			return (NULL);
		}

		str = copy_str(str, nnodde->str);
		strn[aii] = str;
	}
	strn[aii] = NULL;
	return (strn);
}



