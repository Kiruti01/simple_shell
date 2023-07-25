#include "main.h"
/**
 * my_perror - Prints custom error.
 * @argv: Program Name.
 * @c: Error Count.
 * @command: The command.
 * Return: Nothing.
 */
int my_perror(char **argv, int c, char **command)
{
	char *j = my_itoa(c);

	MYPRINTF(argv[0]);
	MYPRINTF(": ");
	MYPRINTF(j);
	MYPRINTF(": ");
	MYPRINTF(command[0]);
	MYPRINTF(": Illegal number: ");
	MYPRINTF(command[1]);
	MYPRINTF("\n");
	free(j);
	return (-1);
}
