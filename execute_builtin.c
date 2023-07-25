#include "main.h"
/**
 * builtin_echo – Executes a regular echo command.
 * @last_command: Last Command Excuted.
 * @command: Parsed Command.
 * Return: Always 0.
 */
int builtin_echo(char **command, int last_command)
{
	char *p;
	unsigned int pid = getppid();

	if (my_strncmp(command[1], "$?", 2) == 0)
	{
		num_putchar(last_command);
		MYPRINTF("\n");
	}
	else if (my_strncmp(command[1], "$$", 2) == 0)
	{
		print_num(pid);
		MYPRINTF("\n");
	}
	else if (my_strncmp(command[1], "$PATH", 5) == 0)
	{
		p = my_getenv("PATH");
		MYPRINTF(p);
		MYPRINTF("\n");
		free(p);
	}
	else
		return (execute_echo(command));
	return (1);
}

/**
 * execute_builtin – Executes builtin commands.
 * @command: The parsed Command
 * @input: The user input
 * @argv: The program name
 * @counter: Counter
 * Return: Nothing.
 */
void execute_builtin(char **command, char *input, char **argv, int counter)
{
	int i, j = 0;

	if (command[1] == NULL)
	{
		free(input);
		free(command);
		exit(EXIT_SUCCESS);
	}
	while (command[1][j])
	{
		if (is_alpha(command[1][j++]) != 0)
		{
			my_perror(argv, counter, command);
			break;
		}
		else
		{
			i = my_atoi(command[1]);
			free(input);
			free(command);
			exit(i);
		}
	}
}

/**
 * ch_dir - Executes change directory command.
 * @command: The parsed command
 * @last: The last command.
 * Return: 0 on Succes, or 1 if fail.
 */
int ch_dir(char **command, __attribute__((unused)) int last)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (command[1] == NULL)
	{
		value = chdir(getenv("HOME"));
	}
	else if (my_strcmp(command[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
	{
		value = chdir(command[1]);
	}
	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
			perror("hsh");
			return (-1);
		}
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * env_var_d – Shows environment variable.
 * @c: Parsed command.
 * @l: Status of last command.
 * Return: Always 0.
 */
int env_var_d(__attribute__((unused)) char **c, __attribute__((unused)) int l)
{
	size_t i;
	int len;
	ssize_t s;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = my_strlen(environ[i]);
		s = write(1, environ[i], len);

		if (s == -1)
		{
			perror("hsh");
			return (-1);
		}
		s = write(STDOUT_FILENO, "\n", 1);

		if (s == -1)
		{
			perror("hsh");
			return (-1);
		}
	}
	return (0);
}

/**
 * builtin_h – Help display for builtin.
 * @command: The parsed command.
 * @er: the last command.
 * Return: 0 on Success, Otherwise -1 on Failure.
 */
int builtin_h(char **command, __attribute__((unused))int er)
{
	int i, j, k = 1;
	char c;

	i = open(command[1], O_RDONLY);

	if (i < 0)
	{
		perror("Error");
		return (0);
	}
	while (k > 0)
	{
		k = read(k, &c, 1);
		j = write(STDOUT_FILENO, &c, k);

		if (j < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');
	return (0);
}
