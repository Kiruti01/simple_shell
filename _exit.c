nclude "main.h"

/**
 * exit_op - The fucntion that controls exit options
 * @argv: The array of strings
 * Return:True or False
 */

bool exit_op(char **argv)
{
	if ((_strcmp(argv[0], "exit")) == 0)
		return (true);
	return (false);
}
