#include "main.h"

/**
 * main - Entry point of the shell.
 * @argc: Argument Count.
 * @argv:Argument Value.
 *
 * Return: Status of the exit value.
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **command;
	int c = 0, s = 1, st = 0;

	if (argv[1] != NULL)
	{
		read_file(argv[1], argv);
	}
	signal(SIGINT, signal_to_handle);
	while (s)
	{
		c++;
		if (isatty(STDIN_FILENO))
		{
			prompt();
		}
		input = my_getline();

		if (input[0] == '\0')
		{
			continue;
		}
		execute_hist(input);
		command = parse_command(input);

		if (my_strcmp(command[0], "exit") == 0)
		{
			execute_builtin(command, input, argv, c);
		}
		else if (check_builtin(command) == 0)
		{
			st = handle_builtin(command, st);
			free_all(command, input);
			continue;
		}
		else
		{
			st = check_command(command, input, c, argv);
		}
		free_all(command, input);
	}
	return (s);
}

/**
 * check_builtin - Checks if a command is a builtin.
 *
 * @cmd: Command to check.
 * Return: 0 on success, otherwise -1 on failure.
 */
int check_builtin(char **command)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;

	if (*command == NULL)
	{
		return (-1);
	}
	while ((fun + i)->command)
	{
		if (my_strcmp(command[0], (fun + i)->command) == 0)
		{
			return (0);
			i++;
		}
		return (-1);
	}
/**
 * signal_to_handle - SIGINT signal handler.
 * @signum: Signal number.
 * Return: Nothing.
 */
void signal_to_handle(int signum)
{
	ssize_t write_result;
	(void) signum;
	write_result = write(STDOUT_FILENO, "\n", 1);

	(void) write_result;
	prompt();
}
/**
 * environ_var - Array of enviroment variable.
 * @env: Array of enviroment variable.
 * Return: Nothing.
 */
void environ_var(char **env)
{
	int i;

	for (i = 0; environ[i]; i++)
		env[i] = my_strdup(environ[i]);
	env[i] = NULL;
}
