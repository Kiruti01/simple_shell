#include "main.h"
/**
 * execute_hist - Writes the user input to a history file.
 * @input: User input
 * Return: 0 on success, otherwise -1 on failure.
 */
int execute_hist(char *user_input)
{
	char *fn = ".hsh_history";
	ssize_t fd, j;
	int i = 0;

	if (!fn)
	{
		return (-1);
	}
	fd = open(fn, O_CREAT | O_RDWR | O_APPEND, 00600);

	if (fd < 0)
	{
		return (-1);
	}
	if (user_input)
	{
		while (user_input[i])
		{
			i++;
		}
		j = write(fd, user_input, i);

		if (j < 0)
		{
			return (-1);
		}
	}
	return (1);
}

/**
 * env_var - Frees the mem alloc for the env variable array.
 * @env:  Environment variables.
 * Return: Nothing.
 */
void env_var(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		free(env[i]);
	}
}
