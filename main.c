#include "main.h"
#include "input.h"
#include "shell.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv, char **envp)
{
	run_shell(envp);
	return (0);
}

/**
 * run_shell - The main function that runs the shell.
 * Displays the shell prompt, reads input, and excts cmd
 */

void run_shell(char **envp)
{
	char *command;

	while (1)
	{
		/*display the prompt and wait for user input*/
		write(STDOUT_FILENO, "My_Simple_Shell $ ", 18);

		/* Read the command from the user */
		command = get_user_input();

		/* Check if end of file (Ctrl+D) or error */
		if (command == NULL)
		{
			/* Handle end of file (Ctrl+D) */
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		/* Remove the trailing newline character */
		remove_newline(command);

		/* Execute the command */
		execute_command(command, envp);

		/* Free the allocated memory for the command */
		free(command);
	}
}
