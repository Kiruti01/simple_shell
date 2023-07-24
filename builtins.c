#include "builtins.h"
#include <unistd.h>
#include <stdio.h>

void execute_env(char **envp)
{
	/*print the current environment variables*/
	for (int i = 0; envp[i] != NULL; i++)
	{
		size_t length = 0;
		while (envp[i][length] != '\0')
			length++;
		write(STDOUT_FILENO, envp[i], length);
		write(STDOUT_FILENO, "\n", 1);
	}
}	    
