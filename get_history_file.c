#include "shell.h"

/**
 * get_history_file - gets the history file
 * @info: parameter struct
 *
 * Return: allocated string containg history file
 * history.c
 */

char *get_history_file(info_t *info)
{
	char *buf, *dir;

	dir = fetchEnvironVariable(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (stringlength(dir) + stringlength(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	copy_str(buf, dir);
	merge_strings(buf, "/");
	merge_strings(buf, HIST_FILE);
	return (buf);
}