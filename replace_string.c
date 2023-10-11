#include "shell.h"
/**
 * replace_string - this func tends to replace strs
 * @prev: ptr to old str
 * @new: new str
 * Return: returns 1 if str was replaced.
 * vars.c
 */
int replace_string(char **prev, char *new)
{
	free(*prev);
	*prev = new;
	return (1);
}

