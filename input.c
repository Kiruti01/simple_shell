#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * get_user_input - Reads input frm std input returns as alloctd string.
 *
 * Return: The user input as a dynamically allocated string.
 */
char *get_user_input(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&input, &len, stdin);

	/* Check if end of file (Ctrl+D) or error */
	if (read == -1)
	{
		/* Free the allocated memory for the input and return NULL */
		free(input);
		return (NULL);
	}

	return (input);
}

/**
 * remove_newline - Removes trailing newline character (\n) frm gvn str
 * @string: The string to process.
 */
void remove_newline(char *string)
{
	size_t length = strlen(string);

	if (string[length - 1] == '\n')
	{
		string[length - 1] = '\0';
	}
}
