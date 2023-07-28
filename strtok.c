#include <stdlib.h>
#include "shell.h"
#include "main.h"

/**
 * updateSavePtrAndModify - Update savePtr and modify input string
 * @modifier: pointer to the current character in the input string
 * @savePtr: pointer to the savePtr variable
 */
void updateSavePtrAndModify(char *modifier, char **savePtr)
{
	if (*modifier == '\0')
		*savePtr = modifier;
	else
		*savePtr = modifier + 1;
	*modifier = '\0';
}

/**
 * isDelim - chk if char is delim
 * @c: character
 * @del: delimeters
 * Return: 1 if delimiter, 0 otherwise
 */

int isDelim(char c, char *del)
{
	while (*del)
	{
		if (c == *del)
			return (1);
		del++;
	}
	return (0);
}

/**
 * _strtok - strtok_r
 * @str: str to be passed
 * @del: delimiters for tokens
 * @savePtr: state
 * Return: nxt token in str, NULL if not found
 */

char *_strtok(char *str, char *del, char **savePtr)
{
	char *ptr, *modifier, *end;
	int quoteFound = 0;

	if (*savePtr)
		ptr = *savePtr;
	else
		ptr = str;
	end = ptr;
	while (*end)
		end++;
	while (*ptr && isDelim(*ptr, del))
		ptr++;
	modifier = ptr;
	if (*ptr == '\0')
	{
		return (NULL);
	}
	if (*ptr == '\'')
	{
		ptr++;
		modifier = _strchr(ptr, '\'');
		if (!modifier)
		{
			_printf("no matching quote found!\n");
			exit(-1);
		}
		*modifier = '\0';
		*savePtr = modifier + 1;
		return (_strdup(ptr));
	}
	while (*modifier)
	{
		if (*modifier == '\'')
			quoteFound = 1;
		if (isDelim(*modifier, del) && quoteFound == 0)
			break;
		modifier++;
	}
	updateSavePtrAndModify(modifier, savePtr);
	return (_strdup(ptr));
}
