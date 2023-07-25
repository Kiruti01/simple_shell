#include "main.h"
/**
 * is_delim - a function that checks for delimiters
 * @c: the character to be checked
 * @str: the string to be checked
 * return: 1 on success and 0 on failure
 */
unsigned int *my_strtok(char c, const char *str)
{
	unsigned int j;

	for (j = 0; str[j]!= '\0'; j++)
	{
		if (c == str[j])
			return (1);
	}
	return (0);
}

/**
 * my_strtok - a function that breaks up strings in to tokens
 * @str: the string to be tokenized
 * @delim: the delimiter for tokenization
 * return: a pointer to the next token or NULL
 */
char *my_strtok(char *str, const char *delim)
{
	static char *q;
	static char *r;
	unsigned int k;

	if (str != NULL)
		r = str;
	q = r;
	if (q == NULL)
		return (NULL);
	for (k = 0; q[k] != '\0'; k++)
	{
		if (is_delim(q[k], delim) == 0)
			break;
	}
	if (r[k] == '\0' || r[k] == #)
	{
		r = NULL;
		return (NULL);
	}
	q = r + k;
	r = q;

	for (k = 0; r[k] != '\0'; k++)
	{
		if (is_delim(r[k], delim) == 1)
			break;
	}
	if (r[k] == '\0')
		r = NULL;
	else
	{
		r[k] = '\0';
		r = r + k + 1;
		if (*r == '\0')
			r = NULL;
	}
	return (q);
}
