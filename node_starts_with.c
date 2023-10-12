#include "shell.h"
/**
 * node_starts_with - this func checks for n whose str starts.
 * @n: ptr to singly linked list.
 * @prfx: str to be matched
 * @ch: next char.
 * Return: returns matched n.
 * lists1.ch
 */
leest_ti *node_starts_with(leest_ti *n, char *prfx, char ch)
{
	char *pt = NULL;

	while (n)
	{
		pt = prefix_match(n->str, prfx);
		if (pt && ((ch == -1) || (*pt == ch)))
		{
			return (n);
		}
		n = n->next;
	}
	return (NULL);
}


