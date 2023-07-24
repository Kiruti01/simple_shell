#include "main.h"

/**
 * _getenv - The function returns all paths
 * @env: The current environment variables
 * @name: The variable key
 * Return: PATH, if successful
 *         NULL, if otherwise
 */

char *_getenv(char **env, char *environ[])
{
	char **s;

	x = _environ;
	while (*s != NULL)
	{
		if ((*s)[_strlen(str)] == '=' && _strcmp(*s, env, _strlen(env)) == 0)
			return (&(*s)[_strlen(env) + 1]);
		s++;
	}
	return (NULL);
}
