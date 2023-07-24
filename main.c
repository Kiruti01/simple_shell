#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "shell.h"


/**
 * list_to_char_array - Converts a list of strings to a char *const * array.
 * @list: Pointer to the head of the list.
 *
 * Return: Char *const * array on success, NULL on failure.
 */
char *const *list_to_char_array(list_t *list)
{
	size_t size = 0;
	list_t *tmp = list;
	char *const *env_array = NULL;
	unsigned int i = 0;

	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}

	env_array = malloc(sizeof(char *) * (size + 1));
	if (!env_array)
		return (NULL);

	tmp = list;
	while (tmp)
	{
		env_array[i] = tmp->str;
		tmp = tmp->next;
	}

	env_array = malloc(sizeof(char *) * (size + 1));
	if (!env_array)
		return (NULL);

	tmp = list;
	for (i = 0; i < size; i++)
	{
		env_array[i] = strdup(tmp->str); /* Copy the string into the allocated memory*/
		if (!env_array[i])
		{
			for (unsigned int j = 0; j < i; j++)
				free(env_array[j]);
			free(env_array);
			return (NULL);
		}
		tmp = tmp->next;
	}
	env_array[i] = NULL;

	return (env_array);
}

/**
 * run_command - Execute a command in the shell
 * @params: Pointer to the param_t struct containing command parameters
 *
 * Description: This function takes a command specified in the params struct,
 * checks if it is a built-in command, and executes it if it is. If the command
 * is not a built-in, it is treated as an external command and executed using
 * the execve system call.
 */
void run_command(param_t *params)
{
	void (*builtin_func)(param_t *) = get_builtin(params);
	if (builtin_func)
	{
	builtin_func(params);
		return; /* We're done with the command execution*/
	}

	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execve(params->args[0], params->args, list_to_char_array(params->env_head))== -1);
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
		/* Parent process */
		wait(&status);
		if (WIFEXITED(status))
			params->status = WEXITSTATUS(status);
	}
}							    
