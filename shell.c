#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_COMMAND_LENGTH 100

/* Define prompt as a global variable*/
const char prompt[] = "My_shell :)$ ";

/**
 * Display_prompt - Displays the shell prompt
 */
void display_prompt(void)
{
    write(STDOUT_FILENO, prompt, strlen(prompt));
}

/**
 * execute_command - Executes given cmd using execve
 * @command: the cmd to execute
 * @args: array of argumnts for cmd
 */

void execute_command(char *command, char *args[])
{
    pid_t pid = fork();

    if (pid < 0)
    {
        write(STDERR_FILENO, "Fork Failed.\n", 13);
        return;
    }
    else if (pid == 0)
    {
	    /*Child process*/
	    /* Child process */
	    char path[] = "/bin/";

	    strcat(path, command);

	    execve(path, args, NULL);
	    perror("Command execution failed");
	    exit(EXIT_FAILURE);
    }
    else
    {
	    /* Parent process */
	    int status;
	    wait(&status);
    }
}        
