#include "main.h"

/**
 * handle_builtin - Handles built-in commands.
 * @command: Parsed command and its arguments.
 * @er: Status of the last execution.
 *
 * Return: 0 on success, Otherwise -1 on failure.
 */
int handle_builtin(char **command, int er)
{
	 bul_t bil[] = {
		{"cd", ch_dir},
		{"env", env_var_d},
		{"help", builtin_h},
		{"echo", builtin_echo},
		{"history", exec_hist},
		{NULL, NULL}
	};
	int i = 0;

	while ((bil + i)->command)
	{
		if (my_strcmp(command[0], (bil + i)->command) == 0)
		{
			return ((bil + i)->fun(command, er));
		}
		i++;
	}
	return (-1);
}
/**
 * check_command - Executes a parsed command.
 * @command: Parsed command and its arguments.
 * @input: User input line.
 * @c: Execution time case for command not found.
 * @argv: Program name.
 *
 * Return: 1 if command Null, -1 on wrong Command and
 * 0 if command is executed.
 */
int check_command(char **command, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*command == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (my_strncmp(*command, "./", 2) != 0 && my_strncmp(*command, "/", 1) != 0)
		{
			path_handler(command);
		}

		if (execve(*command, command, environ) == -1)
		{
			print_error(command[0], c, argv, NULL);
			free(input);
			free(command);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}

/**
 * signal_hanler - Executes the function ^C
 * @sig: Captured signal.
 * Return: Nothing.
 */
int signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		MYPRINTF("\n$ ");
		return (-1);
	}
	return (0);
}
