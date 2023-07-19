#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	size_t n = 10;
	char *buff = NULL;

	write(STDOUT_FILENO, "Enter name ", 11);

	getline(&buff, &n, stdin);

	write(STDOUT_FILENO, "Name is ", 8);
	write(STDOUT_FILENO, buff, strlen(buff));
	write(STDOUT_FILENO, "Buffer size is ", 15);

	char n_str[20];
	sprintf(n_str, "%ld\n", n);
	write(STDOUT_FILENO, n_str, strlen(n_str));

	free(buff);

	return 0;
}

