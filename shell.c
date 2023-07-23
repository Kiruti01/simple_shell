#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

void run_shell(void)
{
<<<<<<< HEAD
	char command[MAX_COMMAND_LENGTH];
	char prompt[] = "simple_shell:) -> ";
=======
    char input[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS + 1[;MAX_COMMAND_LENGTH];
    char prompt[] = "simple_shell :) -> ";
>>>>>>> 35a227e5c9e8d2b42853c4762f7b9e45c4fcd51d

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

<<<<<<< HEAD
		/* Remove the trailing newline character*/
		command[strcspn(command, "\n")] = '\0';

		/* Fork a new process to execute the command*/
		pid_t pid = fork();
=======
        /*Read the command from the user*/
        if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL)
        {
            /* Handle end of file (Ctrl+D)*/
            printf("\n");
            break;
        }

        /* Remove the trailing newline character*/
        input[strcspn(command, "\n")] = '\0';

        /* Tokenize input into command and arg*/
        int argc = 0;
        char *token = strtok(input, " ");
        while (token != NULL && argc < MAX_ARGUMENTS)
        {
            arguments[argc] = token;
            argc++;
            token = strtok(NULL, " ");
        }

        arguments[argc] = NULL; /* terminate arg array*/
>>>>>>> 35a227e5c9e8d2b42853c4762f7b9e45c4fcd51d

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

<<<<<<< HEAD
			waitpid(pid, &status, 0);
		}
	}
=======
        if (pid == -1)
        {
            /*Forking error*/
            perror("fork");
        }
        else if (pid == 0)
        {
            /*Child process: execute the command*/
            if (execvp(arguments[0], arguments) == -1)
            {
                /*Command not found or execution error*/
                perror("execvp");
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
>>>>>>> 35a227e5c9e8d2b42853c4762f7b9e45c4fcd51d
}
