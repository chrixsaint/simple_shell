#include "shell.h"
/**
 * prints_half - This function prints the second half of a string.
 * @str: This is a parameter.
 */
void prints_half(char *str)
{
    int l;
	int n;

    l = 0;

    while (str[l] != '\0')
    {
        l++;
    }
    
    n = (l - 1) / 2;
	printf("The value of n is %d\n", n);
}
