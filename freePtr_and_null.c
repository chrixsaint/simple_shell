#include "shell.h"

/**
 * freePtr_and_null - Frees a pointer and sets it to NULL.
 * @ptr: The address of the pointer to be freed and set to NULL.
 *
 * This function frees the memory pointed to by the given pointer
 * and then sets the pointer itself to NULL to
 * prevent further access to the freed memory.
 *
 * Return: 1 if the pointer was successfully freed, otherwise 0.
 */

int freePtr_and_null(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
