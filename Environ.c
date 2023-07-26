
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

char *_getenv(char *name, param_t *params)
{
	list_t *ptr = params->env_head;

	while (ptr)
