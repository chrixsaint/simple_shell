#include "shell.h"
/**
 * resize_memory - reassigns mry bloc.
 * @ptr: ptr to prev mry block
 * @prev_size: mry sizeof previous.
 * @new_size: new size.
 * Return: pointer to da ol'block nameen.
 * realloc.c
 */
void *resize_memory(void *ptr, unsigned int prev_size, unsigned int new_size)
{
	char *pt;

	if (ptr == NULL)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == prev_size)
	{
		return (ptr);
	}

	pt = malloc(new_size);
	if (pt == NULL)
	{
		return (NULL);
	}
	prev_size = prev_size < new_size ? prev_size : new_size;
	while (prev_size--)
		pt[prev_size] = ((char *)ptr)[prev_size];
	free(ptr);
	return (pt);
}

