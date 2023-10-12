#include "shell.h"


/**
 * loadCommandHistory - Reads command history from a file
 * and populates the history list.
 * @info: The parameter struct.
 *
 * This function reads command history data from a file,
 * creates a history list with the commands, and associates
 * line numbers with each command.
 *
 * Return: The number of commands loaded from history
 * on success, or 0 on failure.
 */
int loadCommandHistory(DataInfo_tii *info)
{
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	int i, last = 0, linecount = 0;
	char *bupha = NULL, *name_of_file;

	name_of_file = get_history_file(info);
	if (name_of_file == NULL)
		return (0);

	fd = open(name_of_file, O_RDONLY);
	free(name_of_file);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	bupha = malloc(sizeof(char) * (fsize + 1));
	if (bupha == NULL)
		return (0);
	rdlen = read(fd, bupha, fsize);
	bupha[fsize] = 0;
	if (rdlen <= 0)
		return (free(bupha), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (bupha[i] == '\n')
		{
			bupha[i] = 0;
			create_history_node(info, bupha + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		create_history_node(info, bupha + last, linecount++);
	free(bupha);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}


