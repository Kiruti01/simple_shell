#include "main.h"

/**
 * _path - The function returns the path to a command
 * @cmd: The first argument of an array of strings args
 * @all_path: The current PATH
 * Return: Path, if successful
 *         NULL, if otherwise
 */

char *_path(char *cmd, char *all_path)
{
	char *token, *delm = ":", *file_path, *all_path_cp;
	int cmd_len, token_len;
	struct stat st;

	if (cmd == NULL || all_path == NULL)
		return (NULL);
	cmd_len = _strlen(cmd);
	all_path_cp = _strdup(all_path);
	if (all_path_cp == NULL)
		return (NULL);
	token = strtok(all_path_cp, delm);
	while (token != NULL)
	{
		token_len = _strlen(token);
		file_path = malloc(sizeof(char) * (token_len +
					cmd_len + 2));
		if (file_path == NULL)
		{
			free(all_path_cp);
			return (NULL);
		}
		_strcpy(file_path, token);
		_strcat(file_path, "/");
		_strcat(file_path, cmd);
		if (stat(file_path, &st) == 0)
		{
			free(all_path_cp);
			return (file_path);
		}
		free(file_path);
		token = strtok(NULL, delm);
	}
	free(all_path_cp);
	if (stat(cmd, &st) == 0)
		return (cmd);
	return (NULL);
}
