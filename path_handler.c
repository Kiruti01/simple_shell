#include "path_handler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *find_command_in_path(char *command);

int is_executable(const char *path);

char *get_next_directory(char **path);

char *allocate_full_path(const char *directory, const char *command);


/**
 * find_command_in_path - Find full path of given command in PATH env var.
 * @command: Command to be searched in PATH.
 * Return: Full path if found, else NULL.
 */
char *find_command_in_path(char *command)
{
	char *path = getenv("PATH");

	if (path == NULL)
	{
		char error_message[] = "Error: PATH environment variable not set.\n";

		write(STDOUT_FILENO, error_message, strlen(error_message));
		exit(EXIT_FAILURE);
	}

	char *path_copy = strdup(path);

	if (path_copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}

	char *directory;

	char *token = strtok(path_copy, ":");

	while ((directory = get_next_directory(&path_copy)) != NULL)
	{
		full_path = allocate_full_path(directory, command);

		if (is_executable(full_path))
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
	}
	free(path_copy);
	return (NULL);
}

/**
 * is_executable - Check if given path is executable.
 * @path: Path to check.
 * Return: 1 if executable, 0 otherwise.
 */
int is_executable(const char *path)
{
	return (access(path, X_OK) == 0);
}


/**
 * get_next_directory - Get next directory from PATH.
 * @path: Pointer to remaining PATH.
 * Return: Current directory token.
 */
char *get_next_directory(char **path)
{
	char *token = strtok(*path, ":");
	*path = strtok(NULL, "");

	return (token);
}

/**
 * allocate_full_path - Allocate memory for full command path.
 * @directory: Directory where the command is located.
 * @command: Command to append.
 * Return: Pointer to allocated memory for full path.
 */

char *allocate_full_path(const char *directory, const char *command)
{
	size_t len = strlen(directory) + strlen(command) + 2;

	char *full_path = (char *)malloc(len);

	if (full_path == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	snprintf(full_path, len, "%s/%s", directory, command);
	return (full_path);
}
