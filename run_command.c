#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "shell.h"
#include "lists.h"
#include "main.h"

/**
 * run_command - looks path dirs for command and execs
 * @params: parameters
 */
void run_command(param_t *params)
{
	void (*builtin_func)(param_t *) = get_builtin(params);
	if (builtin_func)
	{
		builtin_func(parama);
		return;
	}

	pid_t pid;
	int status;

	
	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		execve(params->args[0], params->args, params->env_head);
		perror("execve");
		exit(127); /* Command not found */
	}
	else if (pid < 0)
	{
		/* Fork failed */
		perror("fork");
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			params->status = WEXITSTATUS(status);
	}
}
