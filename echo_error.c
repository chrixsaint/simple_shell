#include "shell.h"


/**
 * echo_error - Prints an error message to standard error.
 * @info: The parameter and return info struct.
 * @estr: A string containing the specified error type.
 *
 * This function prints an error message to the standard error stream,
 * including the program name, line count, and the provided error message.
 *
 * Return: None.
 */

void echo_error(DataInfo_tii *info, char *estr)
{
	errorOutput(info->fname);
	errorOutput(": ");
	writeDecimal(info->line_count, STDERR_FILENO);
	errorOutput(": ");
	errorOutput(info->argv[0]);
	errorOutput(": ");
	errorOutput(estr);
}


