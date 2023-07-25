#include "main.h"

/**
 * path_handler - a function that searches for the
 * $PATH for the executable command
 * @command: parsed user input
 * return: 0 on success otherwise -1 on failure
 */
int path_handler(char **command)
{
	char *p, *q, *_command;
	struct stat buf;

	p = my_getenv("PATH");
	q = my_strtok(p, ":");
	while (q != NULL)
	{
		_command = build(*command, q);
		if (stat(_command, &buf) == 0)
		{
			*command = my_strdup(_command);
			free(_command);
			free(p);
			return (0);
		}
		free(_command);
		q = my_strtok(NULL, ":");
	}
	free(p);
	return (1);
}

/**
 * build - a function that builds a command
 * @token: executable command
 * @value: directory with a command
 * return: parsed path of command otherwise NULL
 */
char *build(char *token, char *dir)
{
	char *command;
	size_t len;

	len = my_strlen(dir) + my_strlen(token) + 2;
	command = malloc(sizeof(char) * len);
	if (command == NULL)
	{
		return (NULL);
	}
	memset(command, 0, len);
	command = my_strcat(command, dir);
	command = my_strcat(command, " /");
	command = my_strcat(command, token);

	return (command);
}

/**
 * my_getenv - gets the value of env var
 * @q: environmental variable name
 * return: the value of the environmental variable or NULL
 */
char *my_getenv(char *q)
{
	char *t;
	size_t r, s;
	int i, j, k;

	r = my_strlen(q);
	for (i = 0; environ[i]; i++)
	{
		if (my_strcmp(q, environ[i], r) == 0)
		{
			s = my_strlen(environ[i]) - r;
			t = malloc(sizeof(char) * s);
			if (!t)
			{
				free(t);
				perror("unable to alloc");
				return (NULL);
			}
			k = 0;
			for (j = r + 1; environ[i][j]; j++, k++)
			{
				t[k] = environ[i][j];
			}
			t[k] = '\0';

			return (t);
		}
	}
	return (NULL);
}
