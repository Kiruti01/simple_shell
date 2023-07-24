#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/**
 * execute_command - Excts gvn cmd using fork and exec functions.
 * @command: The command to execute.
 */

void execute_command(char *command)
{
	/* Check if the command is "/bin/ls"*/
	if (strcmp(command, "/bin/ls") == 0)
	{
		/* Fork a new process to execute the command*/
		pid_t pid = fork();

		if (pid == -1)
		{
			/* Forking error*/
			perror("fork");
		}
		else if (pid == 0)
		{
			/* Child process: execute the command*/
			execute_full_path(command);

			/* Exit the child process after execution */
			exit(EXIT_SUCCESS);
		}
		else
		{
			/* Parent process: wait for the child to complete */
			int status;

			waitpid(pid, &status, 0);
		}
	}
	else
	{
		/* Output an error message for unsupported commands */
		char error_message[] = "Command not supported. Only /bin/ls is allowed.\n";

		write(STDOUT_FILENO, error_message, strlen(error_message));
	}
}

/**
 * execute_full_path - Executes the givn cmd wen full path provided.
 * It directly executes the command using execlp.
 * @command: The command to execute.
 */

void execute_full_path(char *command)
{
	if (execlp(command, command, (char *)NULL) == -1)
	{
		/* Command not found or execution error */
		char error_message[] = "Command not found: No such file or directory \n";

		write(STDOUT_FILENO, error_message, strlen(error_message));
		exit(EXIT_FAILURE);
	}
}

/**
 * execute_with_path - Exctes givn cmd wen full path not provided.
 * It prepends "/bin/" to cmd n tries to excte using execlp.
 * @command: The command to execute.
 */

void execute_with_path(char *command)
{
	char bin_command[100];

	snprintf(bin_command, sizeof(bin_command), "/bin/%s", command);

	if (execlp(bin_command, command, (char *)NULL) == -1)
	{
		/* Command not found or execution error */
		char error_message[] = "Command not found: No such file or directory\n";

		write(STDOUT_FILENO, error_message, strlen(error_message));
		exit(EXIT_FAILURE);
	}
}
