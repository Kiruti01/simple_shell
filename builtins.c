#include "builtins.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "shell.h"
#include "lists.h"
#include "main.h"


/**
 * get_builtin - Get built-in function
 * @params: Pointer to the param_t struct containing command parameters
 */

void (*get_builtin(param_t *params))(param_t *)
{
	op_t ops[] = {
		{"exit", _myExit},
		{"clear", _clear},
		{"env", _printenv},
		{"setenv", _setenv},
		{"cd", _cd},
		{"unsetenv", _unsetenv},
		{"alias", _alias},
		{NULL, NULL},
	};
	op_t *op = ops;

	while (op->name)
	{
		if (!_strcmp(params->args[0], op->name))
			return (op->func);
		op++;
	}
	return (NULL);
}


/**
 * execute_env - Fnctn print crnt env vars.
 * @envp: Pointer to array of strs cntng env vars.
*/

void execute_env(char **envp)
{
	/*print the current environment variables*/
	for (int i = 0; envp[i] != NULL; i++)
	{
		size_t length = 0;

		while (envp[i][length] != '\0')
			length++;
		write(STDOUT_FILENO, envp[i], length);
		write(STDOUT_FILENO, "\n", 1);
	}
}
