#include "shell.h"

/**
 * commandLineReader - Reads the next line of input from STDIN into a buffer.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @ptr: Address of a pointer to a buffer where the input will be stored.
 * @length: Size of the preallocated buffer if not NULL.
 *
 * This function reads the next line of input from STDIN and stores it in the
 * buffer pointed to by `ptr`.
 *
 * Return: The number of characters read (positive), 0 if
 * the end of the file is reached, or -1 on failure.
 */

int commandLineReader(DataInfo_tii *info, char **ptr, size_t *length)
{
	char *pee, *cee, *fresh_ptr;
	static char bupha[READ_BUF_SIZE];
	size_t kai;
	int a = 9;
	int b = 0;
	static size_t aii, lentt;
	ssize_t arr, ess;

	fresh_ptr = NULL;
	pee = NULL;
	pee = *ptr;
	arr = 0, ess = 0;
	if (pee && length)
		ess = *length;
	if (aii == lentt)
		aii = lentt = 0;
	swap_int(b, a);
	arr = readBufferContent(info, bupha, &lentt);
	if (arr == -1 || (arr == 0 && lentt == 0))
	{
		return (-1);
	}


	cee = searchCharInStr(bupha + aii, '\n');
	kai = cee ? 1 + (unsigned int)(cee - bupha) : lentt;
	fresh_ptr = resize_memory(pee, ess, ess ? ess + kai : kai + 1);
	if (fresh_ptr == NULL)
		return (pee ? free(pee), -1 : -1);

	if (ess)
	{
		concatenateLimitedString(fresh_ptr, bupha + aii, kai - aii);
	}
	else
		copyLimitedString(fresh_ptr, bupha + aii, kai - aii + 1);

	ess += kai - aii;
	aii = kai;
	pee = fresh_ptr;

	if (length)
		*length = ess;
	*ptr = pee;
	return (ess);
}

