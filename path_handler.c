#include "path_handler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* find_command_in_path(const char* command)
{
	char* path = getenv("PATH");
	if (path == NULL)
	{
		char error_message[] = "Error: PATH environment variable not set.\n";
		write(STDOUT_FILENO, error_message, strlen(error_message));
		exit(EXIT_FAILURE);
	}

	char* path_copy = strdup(path);

	if (path_copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}

	char* directory;
	char* token = strtok(path_copy, ":");

	while (token != NULL)
	{
		size_t len = strlen(token) + strlen(command) + 2;
		char* full_path = (char*)malloc(len);
		if (full_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		snprintf(full_path, len, "%s/%s", token, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
