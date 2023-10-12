#include "shell.h"


/**
 * fetchEnvironVariable - Retrieves the value of an environment variable.
 * @info: The structure containing potential arguments, used to maintain
 *        constant function prototype.
 * @name: The name of the environment variable to retrieve.
 *
 * This function searches for the specified environment
 * variable by name and returns its value.
 *
 * Return: A pointer to the value of the environment
 * variable or NULL if not found.
 */
char *fetchEnvironVariable(DataInfo_tii *info, const char *name)
{
	leest_ti *nnodde;
	char *ptr;

	nnodde = info->env;
	while (nnodde)
	{
		ptr = prefix_match(nnodde->str, name);
		if (ptr && *ptr)
		{
			return (ptr);
		}
		nnodde = nnodde->next;
	}
	return (NULL);
}
