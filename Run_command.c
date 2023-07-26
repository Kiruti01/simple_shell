#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "shell.h"
#include "lists.h"
#include "main.h"
/**
 * run_command - looks for path dirs for command and execs
 * @params: parameters
 */
void run_command(param_t *params)
{
	char *exeFile = NULL;
	pid_t pid;
	void (*buildin)(param_t *);

	buildin = get_builtin(params);
	if (buildin)
	{
		buildin(params);
		return;
