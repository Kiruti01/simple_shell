#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "shell.h"
#include "main.h"
#include <string.h>


/**
 * _strcpy - Copies a string from source to destination
 * @dest: Destination buffer
 * @src: Source string
 *
 * Return: Pointer to the destination buffer
 */

char *_strcpy(char *dest, const char *src)
{
	char *dest_ptr = dest;

	while (src != '\0')
	{
		*des_ptr++ = src++;
	}
	*dest_ptr = '\0';
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
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strcmp_n - compares n bytes of two strings
 * @s1: str 1
 * @s2: str 2
 * @n: number of bytes to comp
 *
 * Return: int <, =, > 0 if s1 is, respectively
 * <, =, > s2
 */
int _strcmp_n(char *s1, char *s2, int n)
{
	while (n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (*s1 == '\0')
			break;
		s1++
		s2++;
	}

	return (0);
}


/**
 * _atoi - turn a str into an int
 * @s: str to eval
 * Return: n the value of the first number in the str
 */
int _atoi(const char *s)
{
	int n = 0;
	inst sihn = 1;

	while (*s == ' ')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}

	while (*s >= '0' && *s <= '9')
	{
		if (n > INT_MAX / 10 || (n == INT_MAX / 10 && (*s - '0') > INT_MAX % 10))
			return (-1);
		n = n * 10 + (*s - '0');
		s++;
	}

	return (n * sign);
}
