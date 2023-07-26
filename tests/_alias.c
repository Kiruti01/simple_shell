#include <stdlib.h>
#include "shell.h"
#include "main.h"
#include "lists.h"
/**
 * _alias - Implmnts the "alias" shell cmd.
 * @params: Pnter  param_t struct with shell state and args.
 *
 * This function defines new aliases or prints existing aliases in the shell.
 *
 */
void _alias(param_t *params)
{
	unsigned int i;

	if (params->tokCount == 1)
	{
		/* If called with no args, prnt all existing aliases. */
		print_all_aliases(params);
		return;
	}
	for (i = 1; i < params->tokCount; i++)
	{
		if (_strchr(params->args[i], '='))
			set_alias(params->args[i], params);
		else
			print_alias(params->args[i], params);
	}
}

/**
 * set_alias - creats new alias updates an existing one
 * @name: the name of the alias set
 * @params: shell state
 *
 * Return: void
 */
void set_alias(char *name, param_t *params)
{
	char *val, *tmp = NULL;
	unsigned int i = 0, j = 1;

	while (name[i] && name[i] != '=')
		i++;
	if (name[i + 1] == '\'')
	{
		if (_strchr(&name[i + 2], '\''))
		{
			tmp = _strchr(&name[i + 2], '\'');
			*tmp = '\0';
			val = _strdup(&name[i + 2]);
			if (tmp[1] != '\0')
			{
				while (tmp[j] &&
					(tmp[j] == ' ' || tmp[j] == '\t' || tmp[j] == '\n'))
					j++;
				if (tmp[j] != '\0')
					set_alias(&tmp[j], params);
			}
		}
		else
		{
			_printf("Usage: alias name='value' [...]\n");
			return;
		}
	}
	else
		val = _strdup(&name[i + 1]);
	name[i] = '\0'; /* set = to terminater */
	make_alias(name, val, params);
}

/**
 * make_alias - creates new alias adds it to the alias list
 * @name: name of the alias
 * @val: value of the alias
 * @params: parameter struct containing the alias list
 */

void make_alias(char *name, char *val, param_t *params)
{
	list_t *h = params->alias_head;

	while (h)
	{
		if (!_strcmp(name, h->str))
		{
			free(h->val);
			h->val = val;
			h->valLen = _strlen(val);
			params->status = 0;
			return;
		}
		h = h->next;
	}
	/* env var DNE */

	params->alias_head = add_node(&(params->alias_head), name, val);
	free(val);
	params->status = 0;
}
