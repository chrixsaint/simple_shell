#include "shell.h"
/**
 * resetAlias - alias is converted to string
 * @info: users args.
 * @str: alias str.
 * Return: returns 0 on succes.
 * builtin1.ctr
 */
int resetAlias(DataInfo_tii *info, char *str)
{
	char *my_ptr;
	char ctr;
	int result, a = 0, b = 1;

	my_ptr = searchCharInStr(str, '=');
	if (!my_ptr)
	{
		return (1);
	}
	swap_int(b, a);
	ctr = *my_ptr;
	*my_ptr = 0;
	result = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*my_ptr = ctr;
	return (result);
}


