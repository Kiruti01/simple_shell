#include <stdlib.h>
#include "shell.h"
#include "main.h"
#include "lists.h"

/**
 * print_alias - outputs the val of alias, if exists
 * @name: name of the alias to print
 * @params: parameter struct containing the alias list
 * error message is printed to stderr.
 */
void print_alias(char *name, param_t *params)
{
	unsigned int len = 0;
	list_t *ptr = params->alias_head;

	len = _strlen(name);
	while (ptr)
	{
		if (_strcmp_n(name, ptr->str, len - 1) == 0)
			_printf("%s=\'%s\'\n", ptr->str, ptr->val);
		ptr = ptr->next;
	}
	params->status = 0;
}

/**
 * print_all_aliases - prints all aliases in the alias list
 * @params: parameter struct containing the alias list
 */
void print_all_aliases(param_t *params)
{
	print_list_alias(params->alias_head);
	params->status = 0;
}

/**
 * print_list_alias - prints the name and value of each alias in a linked list
 * @head: pointer to the head of the linked list
 */
void print_list_alias(list_t *head)
{
	if (head)
	{
		print_list_alias(head->next);
		if (head->str != NULL)
			_printf("%s=\'%s\'\n", head->str, head->val);
	}
}
