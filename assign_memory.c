#include "shell.h"

#include "shell.h"

/**
 * assign_memory - Fills a memory area with a constant byte.
 * @s: Pointer to the memory area to be filled.
 * @b: The byte to fill the memory area with.
 * @n: The number of bytes to be filled.
 *
 * This function is used to fill a memory area
 * pointed to by 's' with 'n' bytes of the constant byte 'b'.
 *
 * Return: A pointer to the memory area 's' after filling.
 */

char *assign_memory(char *s, char b, unsigned int n)
{
	unsigned int q;

	q = 0;
	while (q < n)
	{
		s[q] = b;
		q++;
	}
	return (s);
}
