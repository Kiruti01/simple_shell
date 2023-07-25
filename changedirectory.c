#include <unistd.h>
#include <stdlib.h>
#include "shell.h"
#include "main.h"

/**
 * cd_setenv - Set the PWD and OLDPWD environment variables
 * @params: shell parameters
 * @cwd: current working directory
 */
static void cd_setenv(param_t *params, char *cwd)
{
	char **tmpArgs = malloc(sizeof(char *) * 3);

	if (!tmpArgs)
	{
		write(STDERR_FILENO, "cd malloc error\n", 16);
		free_params(params);
		exit(-1);
	}

	tmpArgs[0] = _strdup("setenv");
	tmpArgs[1] = _strdup("OLDPWD");
	tmpArgs[2] = _strdup(_getenv("PWD", params));

	tmpArgs[0] = _strdup("setenv");
	tmpArgs[1] = _strdup("PWD");
	tmpArgs[2] = _strdup(cwd);

	for (int i = 0; i < 6; i++)
	{
		if (!tmpArgs[i])
		{
			write(STDERR_FILENO, "cd malloc error\n", 16);
			free_params(params);
			exit(-1);
		}
	}

	_setenv(params);
	for (int i = 0; i < 3; i++)
	{
		free(tmpArgs[i]);
	}
	free(tmpArgs);
}

/**
 * cd_change_directory - Change current working directory
 * @params: shell parameters
 * @target: target directory
 */
static void cd_change_directory(param_t *params, char *target)
{
	char cwd[1024];

	if (chdir(target) == -1)
	{
		write_error(params, "can't cd to ");
		write(STDERR_FILENO, target, _strlen(target));
		write(STDERR_FILENO, "\n", 1);
		params->status = 0;
		free(target);
		return;
	}

	cd_setenv(params, getcwd(cwd, sizof(cwd)));

	free(target);
}

/**
 * _cd - change current working directory
 * @params: shell parameters
 */
void _cd(param_t *params)
{
	char *target = NULL;

	if (params->tokCount == 1)
	{
		target = _getenv("HOME", params);
		if (!target)
		{
			params->status = 0;
			return;
		}
	}
	else if (params->args[1][0] == '-')
	{
		if (!_strcmp(params->args[1], "-"))
		{
			target = _getenv("OLDPWD", params);
			if (!target)
			{
				params->status = 0;
				target = _getenv("PWD", params);
				_printf("%s\n", target);
				free(target);
				return;
			}
			_printf("%s\n", target);
		}
		else
		{
			params->status = 2;
			_printf("%s: %d: cd: Illegal option %c%c\n",
					params->argv[0], params->lineCount,
					'-', params->args[1][1]);
			return;
		}
	}
	else
	{
		target = _strdup(params->args[1]);
		if (!target)
			handle_memory_error(params);
	}
	cd_change_directory(params, target);
}


/**
 *  * handle_memory_error - Helper function to handle memory allocation errors
 *   * @params: shell parameters
 *    */
static void handle_memory_error(param_t *params)
{
	write(STDERR_FILENO, "cd target malloc error\n", 23);
	free_params(params);
	exit(-1);
}
