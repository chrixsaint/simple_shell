#include "shell.h"
/**
 * main - Entry point for the shell program
 * @ac: Argument count that is number of command-line arguments
 * @av: Argument vector that is array of command-line argument strings
 * Return: 0 on success, 1 on error.
 */
int main(int ac, char **av)
{
	int a = 0;
	int b = 1;
	DataInfo_tii informat[] = { INFO_INIT };
	int effd = 2;

	effd = effd + 3;

	if (ac == 2)
	{
		effd = open(av[1], O_RDONLY);
		if (effd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				errorOutput(av[0]);
				errorOutput(": Can't open ");
				errorOutput(av[1]);
				writeErrorChar('\n');
				writeErrorChar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		informat->readfd = effd;
	}
	swap_int(a, b);
	populate_env_list(informat);
	loadCommandHistory(informat);
	shell_main_process(informat, av);
	return (EXIT_SUCCESS);
}

