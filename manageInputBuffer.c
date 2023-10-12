#include "shell.h"
/**
 * manageInputBuffer - buffers chained commands
 * @info: users inputed commands.
 * @my_buffr: ptr to my_buffr
 * @len: ptr to len of variable.
 * Return: returns size of my_buffr read
 * getLine.c
 */
ssize_t manageInputBuffer(info_t *info, char **my_buffr, size_t *len)
{
	size_t lenPtr = 0;
	ssize_t rdr = 0;

	if (!*len)
	{
		free(*my_buffr);
		*my_buffr = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		rdr = getline(my_buffr, &lenPtr, stdin);
#else
		rdr = commandLineReader(info, my_buffr, &lenPtr);
#endif
		if (rdr > 0)
		{
			if ((*my_buffr)[rdr - 1] == '\n')
			{
				(*my_buffr)[rdr - 1] = '\0';
				rdr = rdr - 1;
			}
			info->linecount_flag = 1;
			remove_comments(*my_buffr);
			create_history_node(info, *my_buffr, info->histcount++);
			{
				*len = rdr;
				info->cmd_buf = my_buffr;
			}
		}
	}
	return (rdr);
}

