#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

void run_shell(void)
{
	char command[MAX_COMMAND_LENGTH];
	char prompt[] = "simple_shell:) -> ";

	while (1)
	{
		/*Display the prompt and wait for user input*/
		write(STDOUT_FILENO, prompt, strlen(prompt));
		/*Read the command from the user*/
		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			/* Handle end of file (Ctrl+D)*/
			printf("\n");
			break;
		}

		/* Remove the trailing newline character*/
		command[strcspn(command, "\n")] = '\0';

		/* Fork a new process to execute the command*/
		pid_t pid = fork();

		if (pid == -1)
		{
			/*Forking error*/
			perror("fork");
		}
		else if (pid == 0)
		{
			/*Child process: execute the command*/
			if (execlp(command, command, (char *)NULL) == -1)
			{
				/* Command not found or execution error */
				perror("execlp");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/*Parent process: wait for the child to complete*/
			int status;

			waitpid(pid, &status, 0);
		}
	}
}
