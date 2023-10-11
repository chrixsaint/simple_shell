#include "shell.h"


/**
 * echo_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void echo_error(info_t *info, char *estr)
{
	errorOutput(info->fname);
	errorOutput(": ");
	writeDecimal(info->line_count, STDERR_FILENO);
	errorOutput(": ");
	errorOutput(info->argv[0]);
	errorOutput(": ");
	errorOutput(estr);
}


