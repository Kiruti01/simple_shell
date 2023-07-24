#include "main.h"

/**
 * main - The shell programme
 * @argc: The number of argument entered
 * @args: An array of pointers to strings
 * @env: The current environment
 * Description: The program mimics the shell but with less functionality
 * Return: Always 0.
 */

int main(int argc, char **args, char **env)
{
	char *buffer = NULL, **argv, *pnam = args[0], *paths, *f_path, *t_buf;
	size_t n = 0, i, len;
	ssize_t read_n;
	(void) argc;

	while (1)
	{
		signal(SIGINT, sigint_handler);
		if (isatty(STDIN_FILENO) == 1)
			put_prompt();
		read_n = getline(&buffer, &n, stdin);
		if (read_n == -1)
			inter_rupt(buffer);
		t_buf = _strdup(buffer);
		len = white_space(buffer);
		if (len == 0)
		{
			free(buffer);
			continue;
		}
		argv = break_line(t_buf);
		if (exit_op(argv))
		{
			free(t_buf);
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		paths = _getenv(env, "PATH");
		f_path = _path(argv[0], paths);
		if (f_path != NULL)
			call_fork(argv, pnam, f_path, env);
		else
			put_err(pnam, argv[0]);

	}
	for (i = 0; argv && argv[i]; i++)
		free(argv[i]);
	free(argv);
	free(buffer);
	return (0);
}
