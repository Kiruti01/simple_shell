#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

void main
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		if (strlen(command) == 0)
		{
			continue;
		}

		pid_t pid = fork();

		if (pid == 0)
		{
			execlp(command, command, NULL);
			write(STDERR_FILENO, "Error: Command not found\n", 24);
			exit(1);
		}
		else if (pid < 0)
		{
			write(STDERR_FILENO, "Error: Fork failed\n", 19);
			exit(1);
		}
		else
		{
			waitpid(pid, NULL, 0);
		}
	}
}

int main
{
	return (0);
}
