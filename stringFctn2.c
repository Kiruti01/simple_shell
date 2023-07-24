#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "shell.h"
#include "main.h"
/**
 * _strcpy - copies str to anther mem address
 * @src: pointer to source str
 * @dest: pointer to test addrss
 *
 * Return: pointer to the dest
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
 * _strcmp - compares strings
 * @s1: str 1
 * @s2: str 2
 *
 * Return: int lss than, equal to, or grter than 0 if s1 is, respectively
 * less than, equal to, or grter than s2
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

/**
 * _strcmp_n - compares n bytes of strings
 * @s1: str 1
 * @s2: str 2
 * @n: num of bytes to comp
 *
 * Return: int less than, equal to, or grter than 0 if s1 is, respectively
 * less than, equal to, or grter than s2
 */
int _strcmp_n(char *s1, char *s2, int n)
{
	int i = 0, res = *s1 - *s2;

	while (i <= n)
	{
		res = *(s1++) - *(s2++);
		if (res != 0)
			break;
		i++;
	}

	return (res);
}


/**
 * _atoi - turn a str into an int
 * @s: str to evaluate
 * Return: n the value of the 1st number in the st0ring
 */
int _atoi(char *s)
{
	int n, tmp, len, mul = 1;

	n = 0;
	tmp = 0;

	len = _strlen(s);
	len--;
	while (len >= 0)
	{
		tmp = n;
		n = n + (s[len] - '0') * mul;
		if (n < tmp || n > INT_MAX)
			return (-1);
		len--;
		mul *= 10;
	}
	return (n);
}
