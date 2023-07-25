#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "shell.h"
#include "lists.h"
#include "main.h"

/**
 * run_command - Executes the given command by searching for its path and running it
 * @params: The parameters containing the command and arguments
 */

void run_command(param_t *params)
{
	char *exeFile = NULL;
	pid_t pid;
	void (*buildin)(param_t *);

	builtin = get_builtin(params);
	if (builtin)
	{
		builtin(params);
		return;
	}
	exeFile = get_file(params);
	if (!exeFile)
	{
		return;
	}
	pid = fork();
	if (pid < 0)
	{
		free_params(params);
		exit(98);
	}
	else if (pid == 0)
	{
		execve(exeFile, params->args, NULL);
		perror("Execution error");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&params->status);
		params->status = WEXITSTATUS(params->status);
		free(exeFile);
	}
}
