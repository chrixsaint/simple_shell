#include "shell.h"


/**
 * get_path - Find the full path of a command in the PATH string.
 * @info: Pointer to the info struct.
 * @pathstr: The PATH string to search in.
 * @cmd: The command to find in the PATH.
 *
 * This function searches for the specified command in the given
 * PATH string and returns its full path if found.
 *
 * Return: The full path of the command if found, or NULL if not found.
 */
char *get_path(DataInfo_tii *info, char *pathstr, char *cmd)
{
	int aii = 0, pre_positn, a = 0, b = 1;
	char *pattt;

	pre_positn = 0;
	aii = 0;
	if (pathstr == NULL)
	{
		return (NULL);
	}
	if ((stringlength(cmd) > 2) && prefix_match(cmd, "./"))
	{
		if (command_check(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[aii] || pathstr[aii] == ':')
		{
			pattt = replicate_chars(pathstr, pre_positn, aii);
			if (!*pattt)
				merge_strings(pattt, cmd);
			else
			{
				merge_strings(pattt, "/");
				merge_strings(pattt, cmd);
			}
			if (command_check(info, pattt))
			{
				swap_int(b, a);
				return (pattt);
			}
			if (!pathstr[aii])
				break;
			pre_positn = aii;
		}
		aii++;
	}
	return (NULL);
}
