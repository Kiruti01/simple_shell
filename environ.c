#include "main.h"
#include "lists.h"
#include "shell.h"
#include <stdlib.h>

/**
 * _getenv - Gets value of environ var.
 * @name: The name of the environ var to retrieve.
 * @params: Pointer to the param strcte containing the environ lst.
 *
 * Return: A pointer to the val of the environ var, or NULL if not.
 */

void print_environment(char **env)
{
	/* Iterate through each environment variable and print them*/
	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, my_strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;

	}
}
