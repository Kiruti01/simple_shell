#include "main.h"

/**
 * _exit - exits the shell
 * @data: shell_data
 */
void _exit(shell_data *data)
{
	char ***argv = &data->args;
	int status = 0;

	printf("Exiting the shell...\n");
	if ((*argv)[1])
		status = _atoi((*argv)[1]);
	free_shell_data(data);
	exit(status);
}
