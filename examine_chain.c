#include "shell.h"

/**
 * examine_chain - Examines whether to continue chaining commands
 * based on the last command's status.
 * @info: The parameter struct containing various information.
 * @buf: The character buffer storing command strings.
 * @p: The address of the current position in buf.
 * @i: The starting position in buf.
 * @len: The length of the buffer.
 *
 * This function is responsible for examining the status of the
 * last executed command and making a decision regarding whether
 * to continue chaining commands.
 *
 * Return: Void.
 */

void examine_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t jaii;

	jaii = *p;
	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			jaii = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			jaii = len;
		}
	}

	*p = jaii;
}
