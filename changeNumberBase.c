#include "shell.h"



/**
 * changeNumberBase - Converts a number to a string
 * representation in a given base.
 * @num: The number to be converted.
 * @base: The base to which the number should be converted.
 * @flags: Additional conversion flags
 * (e.g., CONVERT_UNSIGNED, CONVERT_LOWERCASE).
 *
 * This function converts the given number 'num' to
 * a string representation in the specified 'base'.
 * The result is returned as a string. The 'flags' parameter
 * can be used to specify additional conversion options,
 * such as whether the number should be treated as unsigned
 * and whether lowercase letters should be used for
 * hexadecimal bases.
 *
 * Return: A string representation of the converted number.
 */
char *changeNumberBase(long int num, int base, int flags)
{
	unsigned long m;
	static char bupha[50];
	char show = 0;
	static char *strng;
	char *pointa;

	m = num;
	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		m = -num;
		show = '-';

	}
	strng = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pointa = &bupha[49];
	*pointa = '\0';

	do	{
		*--pointa = strng[m % base];
		m /= base;
	} while (m != 0);

	if (show)
		*--pointa = show;
	return (pointa);
}
