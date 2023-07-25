#include "main.h"
/**
 * read_file – Reads a command.
 * @file_name: The file name.
 * @argv: The program name.
 * Return: 0 on success, otherwise -1 on failure.
 */
void read_file(char *file_name, char **argv)
{
	FILE *f_name;
	char *k = NULL;
	int c = 0;

	f_name = fopen(file_name, "r");
	if (f_name == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((k = my_getline()) != NULL)
	{
		c++;
		check_file(k, c, f_name, argv);
	}
	if (k)
		free(k);
	fclose(f_name);
	exit(0);
}
/**
 * * check_file – Checks a parsed command.
 * @line: A line in a file.
 * @c: Error counter.
 * @fd: File Descriptor.
 * @argv: Program Name.
 * Return: Nothing.
 */
void check_file(char *line, int counter, FILE *fd, char **argv)
{
	char **command;
	int st = 0;

	command = parse_command(line);

		if (my_strncmp(command[0], "exit", 4) == 0)
		{
			exit_builtin(command, line, fd);
		}
		else if (check_builtin(command) == 0)
		{
			st = handle_builtin(command, st);
			free(command);
		}
		else
		{
			st = check_command(command, line, counter, argv);
			free(command);
		}
}
/**
 * exit_builtin– Exits the hsh.
 * @line: Line.
 * @command: Parsed command.
 * @fd: File descriptor.
 * Return : Case Of Exit in A File Line.
 */
void exit_builtin(char **command, char *line, FILE *fd)
{
	int j, i = 0;

	if (command[1] == NULL)
	{
		free(line);
		free(command);
		fclose(fd);
		exit(errno);
	}
	while (command[1][i])
	{
		if (is_alpha(command[1][i++]) < 0)
		{
			perror("illegal number");
		}
	}
	j = my_atoi(command[1]);
	free(line);
	free(command);
	fclose(fd);
	exit(j);
}

