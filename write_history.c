#include "shell.h"
/**
 * write_history - makes history file.
 * @info: users arguments.
 * Return: returns 1.
 * history.c
 */
int write_history(DataInfo_tii *info)
{
	leest_ti *n = NULL;
	ssize_t fhandle;
	char *fname;

	fname = get_history_file(info);
	if (!fname)
	{
		return (-1);
	}

	fhandle = open(fname, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(fname);
	if (fhandle == -1)
		return (-1);
	n = info->history;
	while (n != NULL)
	{
		outputStrToFD(n->str, fhandle);
		outputCharToFD('\n', fhandle);
		n = n->next;
	}
	outputCharToFD(BUF_FLUSH, fhandle);
	close(fhandle);
	return (1);
}


