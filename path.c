#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "main.h"
#include "shell.h"
#include "lists.h"

/**
 * check_file_access - Check if the file exists and is executable
 * @filename: Name of the file to check
 * @params: Parameters
 *
 * Return: Valid path to cmd file, NULL if not found or not executable
 */
static char *check_file_access(const char *filename, param_t *params)
{
	if (access(filename, F_OK | X_OK) == 0)
		return (_strdup(filename));

	if (errno == EACCES)
	{
		params->status = 126;
		write_error(params, "Permission denied\n");
	}
	else
	{
		params->status = 127;
		write_error(params, "not found\n");
	}

	return (NULL);
}

/**
 * search_path - Search for the file in the directories listed in PATH
 * @params: Parameters
 *
 * Return: Valid path to cmd file, NULL if not found
 */
static char *search_path(param_t *params)
{
	char *path = _getenv("PATH", params);

	if (!path)
	{
		write_error(params, "not found\n");
		return (NULL);
	}

	char *exePath = _strtok(path, ":", NULL);
	char *exeArg = NULL;

	while (exePath)
	{
		exeArg = str_concat(exePath, "/");
		exeArg = str_concat(exeArg, params->args[0]);

		char *file = check_file_access(exeArg, params);

		if (file)
		{
			free(path);
			return (file);
		}

		free(exePath);
		free(exeArg);

		exePath = _strtok(NULL, ":", NULL);
	}

	free(path);
	return (NULL);
}

/**
 * get_file - Get current path to a command file
 * @params: Parameters
 *
 * Return: Valid path to cmd file, NULL if not found
 */
char *get_file(param_t *params)
{
	if (access(params->args[0], F_OK | X_OK) == 0)
		return (_strdup(params->args[0]));

	return (search_path(params));
}
