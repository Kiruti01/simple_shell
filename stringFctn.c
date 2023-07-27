#include <stdlib.h>

/**
 * str_concat - joins two strings
 * @z1: first str args
 * @z2: second str args
 * Return: Null on failure, else ptr to malloc
 */
char *str_concat(char *z1, char *z2)
{
	char *ptr;
	int i = 0;
	int j = 0;
	int x = 0;

	if (z1 == NULL)
	{
		z1 = "";
	}
	if (z2 == NULL)
	{
		z2 = "";
	}
	while (z1[i] != '\0')
	{
		i++;
	}
	while (z2[j] != '\0')
	{
		j++;
	}
	ptr = malloc((i * sizeof(char)) + (j * sizeof(char)) + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; z1[i] != '\0'; i++)
	{
		ptr[i] = z1[i];
		x++;
	}
	for (j = 0; z2[j] != '\0'; j++)
	{
		ptr[x] = z2[j];
		x++;
	}
	ptr[x] = '\0';
	return (ptr);
}
/**
 * string_nconcat - joins two strings
 * @z1: first str arg
 * @z2: second str arg
 * @n: amount of bytes for z2
 * Return: Null on failure, else ptr to malloc
 */
char *string_nconcat(char *z1, char *z2, unsigned int n)
{
	char *ptr;
	unsigned int i = 0;
	unsigned int j = 0;

	if (z1 == NULL)
	{
		z1 = "";
	}
	if (z2 == NULL)
	{
		z2 = "";
	}
	while (z1[i] != '\0')
	{
		i++;
	}
	while (z2[j] != '\0')
	{
		j++;
	}
	if (n > j)
	{
		n = j;
	}
	ptr = malloc(sizeof(char) * (n + i) + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; z1[i] != '\0'; i++)
	{
		ptr[i] = z1[i];
	}
	for (j = 0; j < n; j++)
	{
		ptr[i + j] = z2[j];
	}
	ptr[i + j] = '\0';
	return (ptr);
}
/**
 *_strlen - returns the len of a str
 *@s: str
 *Return: 0 if null, else len without null byte
 */
int _strlen(char *s)
{
	int length = 0;

	if (s == NULL)
	{
		return (0);
	}

	for (length = 0; s[length] != '\0'; length++)
		;
	return (length);
}

/**
 * _strdup - copy a str to a new allocated block of mem
 * @str: str
 * Return: ptr to duplicated str, NULL if insufficient mem
 */
char *_strdup(char *str)
{
	int len = 0;
	char *ptr = NULL;

	if (!str)
		return (NULL);
	while (*str)
	{
		len++;
		str++;
	}
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr)
	{
		while (len >= 0)
			*(ptr + len--) = *(str--);
	}
	return (ptr);
}

/**
 * _strchr - locates char in a str
 * @s: where to start search
 * @c: values to find
 * Return: ptr to begining of mem area
 */
char *_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (c == '\0')
		return (&s[i]);
	return (0);
}
