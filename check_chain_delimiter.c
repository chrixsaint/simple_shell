#include "shell.h"

/**
 * check_chain_delimiter - Tests if the current character in
 * the buffer is a chain delimiter.
 * @info: The parameter struct.
 * @buf: The character buffer containing the command.
 * @p: The address of the current position in the buffer.
 *
 * This function checks if the current character in
 * the buffer 'buf' at the position 'p' represents
 * a chain delimiter. Chain delimiters are special
 * characters that indicate the chaining of
 * commands (e.g., `|`, `||`, `&`, `&&`, or `;`).
 *
 * If a chain delimiter is found, it modifies the buffer
 * by replacing the delimiter with a null character and
 * updates the 'info' struct with the type of chain delimiter
 * found (e.g., CMD_OR, CMD_AND, or CMD_CHAIN).
 *
 * Return: 1 if a chain delimiter is found, 0 otherwise.
 */

int check_chain_delimiter(info_t *info, char *buf, size_t *p)
{
	size_t k;

	k = *p;
	if (buf[k] == '|' && buf[k + 1] == '|')
	{
		buf[k] = 0;
		k++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[k] == '&' && buf[k + 1] == '&')
	{
		buf[k] = 0;
		k++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[k] == ';')
	{
		buf[k] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
	{
		return (0);
	}
	*p = k;
	return (1);
}
