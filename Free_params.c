#include "lists.h"
#include "shell.h"
#include <stdlib.h>
/**
 * free_params - Frees mem allocated for the param_t struct
 * @params: pnter to the param_t struct to free
 */

void free_params(param_t *params)
{
	unsigned int i;

	if (params->buffer)
		free(params->buffer);
	if (params->nextCommand)
		free(params->nextCommand);
	free_list(params->env_head);
	free_list(params->alias_head);

	for (i = 0; params->args[i]; i++)
		free(params->args[i]);
	free(params->args);
	free(params);
}
