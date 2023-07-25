#include "main.h"
/**
 * parse_command - a function that parses a line of input
 * @input: the users input
 * return: an array of paresed characters
 */
char **parse_command(char *input)
{
	char **ts;
	char *t;
	int i , buffsize = BUFSIZE;

	if (input == NULL)
		return (NULL);
	ts = malloc(sizeof( char *) * buffsize);
	if (!ts)
	{
		perror("hsh");
		return (NULL);
	}
	t = my_strtok(input, "\n ");
	for (i = 0; t; i++)
	{
		ts[i] = t;
		t = my_strtok(NULL, "\n ");
	}
	ts[i] = NULL;
	return (ts);
}
