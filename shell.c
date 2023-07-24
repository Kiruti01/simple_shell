#define _GNU_SOURCE
#include "shell.h"
#include "builtins.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "path_handler.h"
#include <signal.h>
#include "main.h"
#define BUFFER_SIZE 4096
param_t *init_param(char **argv, char **env);

/*static void execute_builtin_command(char *command, char **envp);*/

/*static void execute_path_command(char *command, char **envp);*/


int main(int __attribute__((unused)) argc, char **argv, char **env)
{
	param_t *params = NULL;
	int cond = -2, status;
	unsigned int i;
	char *state = NULL;
	size_t size = BUFFER_SIZE;

	params = init_param(argv, env);
	if (!params)
		exit(-1);
	signal(SIGINT, sigint_handler);
	while (1)
	{
		if (cond == -1)
		{
			status = params->status;
			_printf("BenShell($) \n");
			free_params(params);
			return (status);
		}
		for (i = 0; i < BUFFER_SIZE; i++)
			(params->buffer)[i] = 0;
		params->tokCount = 0;
		if (isatty(STDIN_FILENO))
			_printf("BenShell($): ");
		/*cond = _getline(params);*/
		cond = getline(&params->buffer, &size, stdin);
		params->lineCount++;
		if (cond == -1 && _strlen(params->buffer) == 0)
		{
			status = params->status;
			free_params(params);
			return (status);
		}
		state = NULL;
		params->nextCommand = _strtok(params->buffer, ";\n", &state);
		while (params->nextCommand)
		{
			params->tokCount = process_string(params);
			if (params->tokCount == 0)
				break;
			run_command(params);
			for (i = 0; i < params->argsCap; i++)
			{
				free(params->args[i]);
				params->args[i] = NULL;
			}
			params->tokCount = 0;
			free(params->nextCommand);
			params->nextCommand = _strtok(params->buffer, ";\n",
					&state);
		}
	}
}


/**
 * execute_command - Excts gvn cmd using fork and exec functions.
 * @command: The command to execute
 * @envp: pointr to arr for env vats.
 */

param_t *init_param(char **argv, char **env)
{
	unsigned int i;
	char *eqs = NULL;
	param_t *params = malloc(sizeof(*params));

	if (!params)
		return (NULL);
	params->argsCap = 10;
	params->lineCount = 0;
	params->tokCount = 0;
	params->status = 0;
	params->argv = argv;
	params->nextCommand = NULL;
	params->buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!(params->buffer))
	{
		free(params);
		exit(-1);
	}
	for (i = 0; i < BUFFER_SIZE; i++)
		params->buffer[i] = 0;
	params->args = malloc(sizeof(char *) * params->argsCap);
	if (!(params->args))
	{
		free(params->buffer);
		free(params);
		exit(-1);
	}
	for (i = 0; i < params->argsCap; i++)
		params->args[i] = NULL;
	params->env_head = NULL;
	for (i = 0; env[i]; i++)
	{
		eqs = _strchr(env[i], '=');
		*eqs = '\0';
		params->env_head = add_node(&(params->env_head),
				env[i], eqs + 1);
		if (!(params->env_head))
		{
			free(params->buffer);
			free(params->args);
			free_list(params->env_head);
			free(params);
			exit(-1);
		}
	}
	params->alias_head = NULL;
	return (params);
}


/**
*check if cmd is 'env
	if (strcmp(command, "env") == 0)
	{
		execute_env(envp); / Call the execute_env function from builtins.c*/
		return;
	}

	/* Check if the command is "/bin/ls"
	if (strcmp(command, "/bin/ls") == 0)
	{
		/* Fork a new process to execute the command
		pid_t pid = fork();

		if (pid == -1)
		{
			/* Forking error
			perror("fork");
		}
		else if (pid == 0)
		{
			/* Child process: execute the command
			execute_full_path(command);

			/* Exit the child process after execution 
			exit(EXIT_SUCCESS);
		}
		else
		{
			/* Parent process: wait for the child to complete 
			int status;

			waitpid(pid, &status, 0);
		}
	}
	else
	{
		execute_path_command(command, envp);
	}
}

/**
 * execute_builtin_command - Execute built-in commands.
 * @command: Command to execute.
 * @envp: Pointer to an array for environment variables.
 *

static void execute_builtin_command(char *command, char **envp)
{
	if (strcmp(command, "env") == 0)
	{
		execute_env(envp);
	}
}

/**
 * execute_path_command - Execute commands from PATH.
 * @command: Command to execute.
 * @envp: Pointer to an array for environment variables.
 /
static void execute_path_command(char *command, char **envp)
{
	/* Output an error message for unsupported commands 
	char *full_path = find_command_in_path(command);

	if (full_path != NULL)
	{
		/* Fork a new process to execute the command from PATH
		pid_t pid = fork();

		if (pid == -1)
		{
			/*Forking error
			perror("fork");
		}
		else if (pid == 0)
		{
			/* Child process: execute the command from PATH
			execute_full_path(full_path);
			/* Exit the child process after execution
			exit(EXIT_SUCCESS);
		}
		else
		{
			/* Parent process: wait for the child to complete
			int status;

			waitpid(pid, &status, 0);
		}
		free(full_path);
	}
	else
	{
		/*Output an error message for unsupported commands
		char error_message[] = "Command not found.\n";

		write(STDOUT_FILENO, error_message, strlen(error_message));
	}
}


/**
 * execute_full_path - Executes the givn cmd wen full path provided.
 * It directly executes the command using execlp.
 * @command: The command to execute.
 *

void execute_full_path(char *command)
{
	if (execlp(command, command, (char *)NULL) == -1)
	{
		/* Command not found or execution error *
		char error_message[] = "Command not found: No such file or directory \n";

		write(STDOUT_FILENO, error_message, strlen(error_message));
		exit(EXIT_FAILURE);
	}
}

/**
 * execute_with_path - Exctes givn cmd wen full path not provided.
 * It prepends "/bin/" to cmd n tries to excte using execlp.
 * @command: The command to execute.
 *

void execute_with_path(char *command)
{
	char bin_command[100];

	snprintf(bin_command, sizeof(bin_command), "/bin/%s", command);

	if (execlp(bin_command, command, (char *)NULL) == -1)
	{
		/* Command not found or execution error *
		char error_message[] = "Command not found: No such file or directory\n";

		write(STDOUT_FILENO, error_message, strlen(error_message));
		exit(EXIT_FAILURE);
	}
}
