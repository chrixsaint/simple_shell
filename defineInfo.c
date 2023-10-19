#include "shell.h"


/**
 * defineInfo - Initializes an `DataInfo_tii` struct.
 * @info: Pointer to the `DataInfo_tii` struct to be initialized.
 * @av: Argument vector containing the program name and arguments.
 *
 * This function initializes the fields of an `DataInfo_tii` struct,
 * including setting the program name,
 * tokenizing the argument string, and updating variable values.
 *
 * Return: No return value.
 * getinfo.c
 */

void defineInfo(DataInfo_tii *info, char **av)
{
	int aii;
	int a = 0;
	int b = 8;

	aii = 0;
	info->fname = av[0];
	if (info->arg != NULL)
	{
		info->argv = tokenize_string(info->arg, " \t");
		if (info->argv == NULL)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				swap_int(b, a);
				info->argv[0] = duplicate_strng(info->arg);
				info->argv[1] = NULL;
			}
		}
		while (info->argv && info->argv[aii])
			aii++;
		info->argc = aii;

		replace_alias(info);
		updateVariableValues(info);
	}
}


