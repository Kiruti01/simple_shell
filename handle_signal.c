#include "main.h"

/**
 * sigint_handler - The signal handler for process interruption
 *                  for CNTL + C
 * @sig_int: The int to the user-defined handler
 * Return: Always nothing
 */

void sigint_handler(int sig_int)
{
	if (sig_int == SIGINT)
	{
		put_char('\n');
		put_prompt();
	}
}
