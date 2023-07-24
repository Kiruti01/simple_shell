#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void run_shell(void)
{
	char *command = NULL;
	ssize_t command_len = 0;
	char prompt[] = "my_simple_shell $ ";

	while (1)
	{
		/*display the prompt and wait for user input*/
		write(STDOUT_FILENO, prompt, strlen(prompt));

		/* Read the command from the user*/
		ssize_t input_length = getline(&command, &command_len, stdin);

		/* Check if end of file (Ctrl+D) or error */
		if (input_length == -1)
		{
			/* Handle end of file (Ctrl+D)*/
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		/* Remove the trailing newline character*/
		if (command[input_length - 1] == '\n')
		{
			command[input_length - 1] = '\0';
			input_length--;
		}

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
			if (command[0] == '/')
			{
				/* Full path provided, execute directly */
				if (execlp(command, command, (char*)NULL) == -1)
				{
					/* Command not found or execution error */
					char error_message[] = "Command not found: No such file or directory \n";
					write(STDOUT_FILENO, error_message, strlen(error_message));
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				/* Prepend '/bin/' to the command and try to execute it */
				char bin_command[input_length + 5];/* Room for "/bin/" and null terminator*/
				snprintf(bin_command, sizeof(bin_command), "/bin/%s", command);

				if (execlp(bin_command, command, (char*)NULL) == -1)
				{
					/* Command not found or execution error*/
					char error_message[] = "Command not found: No such file or directory\n";
					write(STDOUT_FILENO, error_message, strlen(error_message));
					free(command);
					exit(EXIT_FAILURE);
				}
			}
		}
		else
		{
			/* Parent process: wait for the child to complete*/
			int status;
			waitpid(pid, &status, 0);
		}
	}
	free(command);
}
