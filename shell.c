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
    if (access(command, X_OK) == 0)
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
            /* check if cmd is '/bin/ls'*/
            if (strcmp(command, "/bin/ls") == 0)
            {
                execve(command, args, NULL);
            }
            else
            {
                char error_msg[100];
                snprintf(error_msg, sizeof(error_msg), "Command not found: %s\n", command);
                write(STDERR_FILENO, error_msg, strlen(error_msg));
                _exit(EXIT_FAILURE);
            }
        }
        else
        {
            /* Parent process*/
            int status;

            wait(&status);
        }
    }