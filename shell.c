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
            execve(command, args, NULL);

            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Execution failed: %s\n", command);
            write(STDERR_FILENO, error_msg, strlen(error_msg));
            _exit(EXIT_FAILURE);
        }
        else
        {
            /* Parent process */
            int status;
            wait(&status);
        }
    }
    else
    {
        /* Command not found in the current directory, try the PATH */
        char *path = getenv("PATH");
        if (path != NULL)
        {
            char *path_copy = strdup(path);
            char *dir = strtok(path_copy, ":");

            while (dir != NULL)
            {
                char *full_path = malloc(strlen(dir) + strlen(command) + 2);
                sprintf(full_path, "%s/%s", dir, command);

                if (access(full_path, X_OK) == 0)
                {
                    /* The command exists and is executable in this directory */
                    pid_t pid = fork();

                    if (pid < 0)
                    {
                        write(STDERR_FILENO, "Fork Failed.\n", 13);
                        free(full_path);
                        free(path_copy);
                        return;
                    }
                    else if (pid == 0)
                    {
                        /* Child process */
                        execve(full_path, args, NULL);

                        char error_msg[100];
                        snprintf(error_msg, sizeof(error_msg), "Execution failed: %s\n", command);
                        write(STDERR_FILENO, error_msg, strlen(error_msg));
                        free(full_path);
                        free(path_copy);
                        _exit(EXIT_FAILURE);
                    }
                    else
                    {
                        /* Parent process */
                        int status;
                        wait(&status);
                        free(full_path);
                        free(path_copy);
                        return;
                    }
                }

                free(full_path);
                dir = strtok(NULL, ":");
            }

            free(path_copy);
        }

        char error_msg[100];
        snprintf(error_msg, sizeof(error_msg), "Command not found: %s\n", command);
        write(STDERR_FILENO, error_msg, strlen(error_msg));
    }
}