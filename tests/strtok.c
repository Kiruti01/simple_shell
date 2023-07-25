#include <stdlib.h>
#include "shell.h"
#include "main.h"
/**
 * isDelim - checks if char is of the delims
 * @c: char
 * @delim: delims
 *
 * Return: 1 if it is a delim, 0 otherwise
 */
int isDelim(char c, char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _find_end_of_token - Finds the end of a token
 * @modifier: starting point to search
 * @delim: delimiters for tokens
 *
 * Return: pointer to the end of the token
 */
static char *_find_end_of_token(char *modifier, char *delim)
{
	int quoteFound = 0;

	while (*modifier)
	{
		if (*modifier == '\'')
			quoteFound = 1;

		if (isDelim(*modifier, delim) && quoteFound == 0)
			break;

		modifier++;
	}

	return (modifier);
}

/**
 * _handle_single_quote - Handles single quotes in the input
 * @ptr: pointer to the starting quote
 * @savePtr: state
 *
 * Return: token enclosed in single quotes
 */
static char *_handle_single_quote(char *ptr, char **savePtr)
{
	ptr++;
	char *modifier = _find_end_of_token(ptr, "\'");

	if (!modifier)
	{
		_printf("no matching quote found!\n");
		exit(-1);
	}

	*modifier = '\0';
	*savePtr = modifier + 1;
	return (_strdup(ptr));
}

/**
 * _strtok - strtok_r
 * @str: str to pass
 * @delim: delims for tokens
 * @savePtr: state
 *
 * Return: next token found in str, NULL if not found
 */
char *_strtok(char *str, char *delim, char **savePtr)
{
	char *ptr, *end;

	if (*savePtr)
		ptr = *savePtr;
	else
		ptr = str;
	end = ptr;
	while (*end)
		end++;
	while (*ptr && isDelim(*ptr, delim))
		ptr++;
	modifier = ptr;
	if (*ptr == '\0')
	{
		return (NULL);
	}
	if (*ptr == '\'')
	return (_handle_single_quote(ptr, savePtr));

	char *modifier = _find_end_of_token(ptr, delim);

	if (*modifier == '\0')
		*savePtr = modifier;
	else
		*savePtr = modifier + 1;

	*modifier = '\0';
	return (_strdup(ptr));
}
