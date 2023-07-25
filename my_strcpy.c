#include "main.h"
/**
 * my_strncmp - a function that comapres a number of char
 * of two strings
 * @s1: first strings
 * @s2: second string
 * return: 1 if the char string does not
 * match otherwise 0
 */
int my_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);
	for (i = 0; i < n && s2[i]; i++)
	{
ii		if (s1[i] != s2[i])
		{
			return (1);
		}
	}

	return (0);
}

/**
 * my_strcat - a function that concatinates two strings
 * @dest: the destination string
 * @src: the second string
 * return: the first string and second string character
 */
char *my_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}

/**
 * my_strchr - a fuction that searches a char in a  string
 * @s: string to search from
 * @c: char to search for
 * return: pointer to char*
 */
char *my_strchr(char *s, char c)
{
	do {
		if (*s == c)
		{
			break;
		}
	} while (*s++);
	return (s);
}

/**
 * my_strcpy - a function that copies a string
 * from source to destination.
 * @dest: destination
 * @src: source
 * return: copy of char*
 */
char *my_strcpy( char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * my_strdup - a function that duplicates a string
 * @str: the string to be dupliccated
 * return: a duplicated string
 */
char *my_strdup(char *str)
{
	size_t len, i;
	char *str2;

	len = my_strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}
	for (i = 0; i <= len; i++)
	{
		str2[i] =str[i];
	}

	return (str2);
}
