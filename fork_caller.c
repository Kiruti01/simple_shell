nclude "main.h"

/**
 * call_fork - The function that create process
 * @argv: An array of pointers to stringd of arguments entered
 * @prog_name: The executable program name
 * @full_path: The full path to the executable commands
 * @env: The current environment
 * Return: nothing
 */
void call_fork(char **argv, char *prog_name, char *full_path, char **env)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror(prog_name);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(full_path, argv, env) == -1)
		{
			perror(prog_name);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
