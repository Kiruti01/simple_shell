#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include <stdio.h>

/**
 * expand_alias - Expand alias and add tokens to args array
 * @params: parameters
 * @token: token to check for alias expansion
 */
static void expand_alias(param_t *params, char *token)
{
	char *state_2 = NULL;
	char *alias = _strdup(get_node(params->alias_head, token)->val);

	if (!alias)
	{
		write(STDERR_FILENO, "alias expansion malloc error\n", 28);
		free_params(params);
		exit(-1);
	}

	char *val = _strtok(alias, " \n\t", &state_2);

	while (val)
	{
		params->args[params->tokCount++] = val;
		if (params->tokCount == params->argsCap)
		{
			params->argsCap += 10;
			params->args = _realloc(params->args,
					params->argsCap - 10,
					params->argsCap);
			if (!params->args)
			{
				write(STDERR_FILENO, "realloc error\n", 14);
				free_params(params);
				exit(-1);
			}
		}
		val = _strtok(NULL, " ", &state_2);
	}

	free(alias);
}

/**
 * process_string - process next cmd into str toks
 * @params: params
 *
 * Return: number of tokens
 */

int process_string(param_t *params)
{
	char *token = NULL, *state = NULL;

	token = _strtok(params->nextCommand, " \n\t", &state);

	if (!token)
	{
		params->tokCount = 0;
		return (0);
	}
	list_t *node = get_node(params->alias_head, token);

	if (node != NULL)
	{
		free(token);
		expand_alias(parans, node->val);
	}
	else
	{
		params->args[(params->tokCount)++] = token;
		if (params->tokCount == params->argsCap)
		{
			params->argsCap += 10;
			params->args = _realloc(params->args,
					params->argsCap - 10,
					params->argsCap);
			if (!params->args)
			{
				write(STDERR_FILENO, "realloc error\n", 14);
				free_params(params);
				exit(-1);
			}
		}
		token = _strtok(NULL, " \n\t", &state);
	}

	return (params->tokCount - 1);
}
