#include "shell.h"
/**
 * readBufferContent - this funcs scans/reads a buffer for content
 * @info: users args.
 * @buf: ptr to buffer
 * @i: size of buff
 * Return: returns fhandle.
 * getLine.c
 */
ssize_t readBufferContent(DataInfo_tii *info, char *buf, size_t *i)
{
	ssize_t fhandle = 0;

	if (*i)
		return (0);
	fhandle = read(info->readfd, buf, READ_BUF_SIZE);
	if (fhandle >= 0)
	{
		*i = fhandle;
	}
	return (fhandle);
}


