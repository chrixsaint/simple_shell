#include "shell.h"
/**
 * merge_strings - merges two given strings.
 * @my_dest: destination space.
 * @my_origin: origin buffer
 * Return: returns ptr to destiny buff.
 * string.c
 */
char *merge_strings(char *my_dest, char *my_origin)
{
	char *my_result;
	
	my_result = my_dest;
	while (*my_dest)
		my_dest++;
	while (*my_origin)
	{
		*my_dest++ = *my_origin++;
	}
	*my_dest = *my_origin;
	return (my_result);
}

