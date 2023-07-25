#include "main.h"

/**
 * _putchar - writes char c to stdout.
 * @c: The character to print.
 *
 * Return: 1 on success, otherwise -1 on failure.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * my_strncpy - copies a string.
 * @dest: A char input destination.
 * @start: A char input.
 * @k: int.
 * Return: char.
 */
char *my_strncpy(char *dest, char *start, int k)
{
	int j;

	j = 0;

	while (j < k && *(start + j))
	{
		*(dest + j) = *(start + j);
		j++;
	}
	while (j < k)
	{
		*(dest + j) = '\0';
		j++;
	}
	return (dest);
}

/**
 * my_strlen – Checks the length of string
 * @str: char to check
 * Return: int
 */
int my_strlen(char *str)
{
	int j;

	for (j = 0; str[j] != '\0'; j++)
	{
		continue;
	}
	return (j);
}

/**
 * my_atoi – converts a string to an int.
 * @str: string
 * Return: int
 */
int my_atoi(char *str)
{
	int i, j, k, l;

	i = k = 0;
	l = 1;

	while ((str[i] < '0' || str[i] > '9') && (str[i] != '\0'))
	{
		if (str[i] == '-')
		{
			l *= -1;
			i++;
		}
	j = i;
	while ((str[j] >= '0') && (str[j] <= '9'))
	{
		k = (k * 10) + l * ((str[j]) - '0');
		j++;
	}
	return (k);
}
/**
 * my_puts - print a string
 * @str: pointer char
 * return: Nothing.
 */
void my_puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
	return;
}
