
#include <stdio.h>
#include <limits.h>
#include "shell.h"
#include "main.h"
/**
 * _strcpy - copies a str to anther mem addrss
 * @src: pointer source str
 * @dest: pointer destn addrss
 *
 * Return: pointer to destn
 */
char *_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dest[i] = '\n';
	return (dest);
}

/**
 * _strcmp - comps two strings
 * @s1: str 1
 * @s2: str 2
 *
 * Return: int >, =, < 0 if s1 is, respectively
 * <, =, > s2
 */
int _strcmp(char *s1, char *s2)
{
	int res = 0;

	do {
		res = *s1 - *s2;
		if (*s1 == 0 || *s2 == 0)
			break;
		s1++;
		s2++;
	} while (res == 0);

	return (res);
}
