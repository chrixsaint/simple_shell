#include"shell.h"
/**
 * sigintHandler - stops ctrl-C
 * @sig_num: signal digit
 * Return: returns void
 * getLine.c
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	write_string("\n");
	write_string("$ ");
	write_char(BUF_FLUSH);
}

