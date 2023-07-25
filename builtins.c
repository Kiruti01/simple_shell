#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"
#include "lists.h"
#include "main.h"

/**
 * get_builtin - check cmd built-in fnctn
 * @av: args list
 *
 * Return: Function pointer to the built-in function. NULL if not found.
 */

void (*get_builtin(char **av))(shell_data * data)
{
	int i;
	builtin_t F[] = {
		{"exit", _myExit},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}};

	for (i = 0; F[i].name != NULL; ++i)
	{
		if (_strcmp(av[0], F[i].name) == 0)
			return (F[i].fun);
	}
	return (NULL);
}
