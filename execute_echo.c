#include "main.h"
/**
 * execute_echo - Handles the normal echo
 * @command: Parsed command.
 * Return: 0 on success, Otherwise -1 on failure.
 */
int execute_echo(char **command)
{
	pid_t pid;
	int j;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", command, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &j, WUNTRACED);
		} while (!WIFEXITED(j) && !WIFSIGNALED(j));
	}
	return (1);
}
/**
 * exec_hist - Displays the history of user input.
 * @c: Parsed command.
 * @s: Status of last executed command.
 * Return: 0 on success, Otherwise -1 on failure.
 */
int exec_hist(__attribute__((unused)) char **c, __attribute__((unused)) int s)
{
	char *fn = ".hsh_hist";
	FILE *fp;
	char *line;
	int index = 0;
	char *k;

	fp = fopen(fn, "r");

	if (fp == NULL)
	{
		return (-1);
	}
	while ((line = my_getline()) != NULL)
	{
		index++;
		k = my_itoa(index);

		MYPRINTF(k);
		free(k);
		MYPRINTF(" ");
		MYPRINTF(line);
		free(line);
	}
	fclose(fp);
	return (0);
}
