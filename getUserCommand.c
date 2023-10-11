#include "shell.h"


/**
 * getUserCommand - Get a line of input from the user
 * without the newline character.
 * @info: Pointer to the parameter struct.
 *
 * This function reads a line of user input
 * and removes the newline character.
 *
 * Return: The number of bytes read.
 */

ssize_t getUserCommand(info_t *info)
{
	static size_t aii, jaii, lentt;
	ssize_t r = 0;
	static char *bupha;
	char **bupha_ptr, *ptr;

	bupha_ptr = &(info->arg);
	write_char(BUF_FLUSH);
	r = manageInputBuffer(info, &bupha, &lentt);
	if (r == -1)
	{
		return (-1);
	}
	if (lentt)
	{
		jaii = aii;
		ptr = bupha + aii;

		examine_chain(info, bupha, &jaii, aii, lentt);
		while (jaii < lentt)
		{
			if (check_chain_delimiter(info, bupha, &jaii))
			{
				break;
			}
			jaii++;
		}

		aii = jaii + 1;
		if (aii >= lentt)
		{
			aii = lentt = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*bupha_ptr = ptr;
		return (stringlength(ptr));
	}

	*bupha_ptr = bupha;
	return (r);
}


