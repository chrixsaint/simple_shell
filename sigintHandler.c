#include"shell.h"


/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 * getLine.c
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	write_string("\n");
	write_string("$ ");
	write_char(BUF_FLUSH);
}