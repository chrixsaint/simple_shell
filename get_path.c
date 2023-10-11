#include "shell.h"


/**
 * get_path - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 * parser.c
 */
char *get_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((stringlength(cmd) > 2) && prefix_match(cmd, "./"))
	{
		if (command_check(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = replicate_chars(pathstr, curr_pos, i);
			if (!*path)
				merge_strings(path, cmd);
			else
			{
				merge_strings(path, "/");
				merge_strings(path, cmd);
			}
			if (command_check(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}