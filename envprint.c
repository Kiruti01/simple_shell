#include "main.h"
#include "lists.h"
#include "shell.h"

/**
 * _printenv - outputs env details
 * @params: params
 * Return: void
 */

void _printenv(param_t *params)
{
	if (params->tokCount != 1)
	{
		_printf("env: %s: No such file or directory\n",
			params->args[1]);
		params->status = 2;
		return;
	}
	print_list_env(params->env_head);
	params->status = 0;
}

/**
 * print_list_env - prints the env vars
 * @head: ptr to the head of the environment list
 */
void print_list_env(list_t *head)
{
	if (head)
	{
		print_list_env(head->next);
		if (head->str)
			_printf("%s=%s\n", head->str, head->val);
	}
}
