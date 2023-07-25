#include <stdlib.h>
#include <limits.h>
#include "shell.h"
#include "main.h"

/**
 * validNum - check str is a valid num
 * @s: str
 *
 * Return: 0 if false, 1 otherwise
 */
int validNum(char *str)
{
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (0);
		str++;
	}
	return (1);
}
/**
 * _myExit - builtin exit funct
 * @params: params
 */
void _myExit(param_t *params)
{
	int exit_status = 0;

	if (!params->args[1])
	{
		exit_status = params->status;
		free_params(params);
		exit(exit_status);
	}
	if (validNum(params->args[1]))
	{
		exit_status = _atoi((params->args)[1]);
		if (exit_status == -1)
		{
			write_error(params, "Illegal number: ");
			write(STDERR_FILENO, params->args[1],
			      _strlen(params->args[1]));
			write(STDERR_FILENO, "\n", 1);
			params->status = 2;
			return;
		}
		free_params(params);
		exit(exit_status);
	}
	else
	{
		params->status = 2;
		write_error(params, "Illegal number: ");
		write(STDERR_FILENO, params->args[1],
		      _strlen(params->args[1]));
		write(STDERR_FILENO, "\n", 1);
	}
}
