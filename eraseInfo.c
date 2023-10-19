#include "shell.h"

/**
 * eraseInfo - Resets an DataInfo_tii struct to initial values.
 * @info: Pointer to the DataInfo_tii struct to be reset.
 *
 * This function clears the fields of an DataInfo_tii struct by
 * setting them to their initial values, effectively resetting the structure.
 *
 * Return: None.
 */
void eraseInfo(DataInfo_tii *info)
{
	int a = 0, b = 2;

	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
	swap_int(b, a);
}


