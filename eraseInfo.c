#include "shell.h"

/**
 * eraseInfo - Resets an info_t struct to initial values.
 * @info: Pointer to the info_t struct to be reset.
 *
 * This function clears the fields of an info_t struct by
 * setting them to their initial values, effectively resetting the structure.
 *
 * Return: None.
 */
void eraseInfo(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}


