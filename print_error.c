#include "main.h"
/**
 * prompt - displays the shll prompt
 */
void prompt(void)
{
	ssize_t write status = write(STDOUT_FILENO, "Cisfun$ \n",8)

		if (write _status == -1)
		{
			perror("hsh");
			return;
		}
}

/**
 * print_error - displays error
 * @input: user input
 * @counter: counter loop
 * @argv: program name
 * @error: error flag
 * return: void
 */
void print_error(char *input,int counter, char **argv, int *error)
{
	ssize_t write status;
	int local_error = 0;
	char *er;

	write_status = write(STDOUT_FILENO, argv[0]), my_strlen(argv[0]);
	if (write_status == -1)
	{
		perror("hsh");
		local_error = 1;
	}
	write_status = write(STDOUT_FILENO, ":", 2);
	if (write_status == -1)
	{
		perror("hsh");
		local_error = 1;
	}
	er = my_itoa(counter);
	write_status = write(STDOUT_FILENO, er, my_strlen(er));
	free(er);
	if (write_status == -1)
	{
		perror("hsh");
		local_error = 1;
	}
	write_status = write(STDOUT_FILENO, ":", 2);
	if (write_status == -1)
	{
		perror("hsh");
		local_error = 1;
	}
	write_status = write(STDOUT_FILENO, input, my_strlen(input));
	if (write_status == -1)
	{
		perror("hsh");
		local_error = 1;
	}
	write_status = write(STDOUT_FILENO, ": No such file or directory\n", 28);
	if (write_status == -1)
	{
		perror("hsh");
		local_error = 1;
	}
	if (local_error)
	{
		*error = 1;
		return;
	}
}
