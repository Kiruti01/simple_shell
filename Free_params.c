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
