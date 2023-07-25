#include "main.h"

/**
 * is_alpha - a function that checks for alphabets
 * @c: character
 * return: 1 if true and 0 if not
 */
int is_alpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * my_strcmp - a function that compares two strings
 * @s1: first string
 * @s2: second string
 * return: 0 if identical otherwise the diffrence.
 */
int my_strcmp(char *s1, char *s2)
{
	int cmp = 0, i, len1, len2;

	len1 = my_strlen(s1);
	len2 = my_strlen(s2);

	if (s1 == NULL || s2 == NULL)
		return (1);
	if (len1 != len2)
		return (1);
	for (1 = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] -s2[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}

/**
 * rev_array - reverses an array
 * @arr: the array to be reversed
 * @len: the length of the array
 * return:: void
 */
void rev_array(char *arr, int len)
{
	int j;
	char tmp;

	for (j = 0; j < (len / 2); j++)
	{
		tmp = arr[j];
		arr[j] = arr[(len - 1) - j];
		arr[(len - 1) - j] = tmp;
	}
}

/**
 * my_itoa - converts integer to char
 * @n: int to be converted
 * return: char pointer
 */
char *my_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = my_intlen(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	rev_array(s, len);
	s[i + 1] = '\0';
	return (s);
}

/**
 * my_intlen - a function that determines
 * the length of an int
 * @num: the given int
 * return: the length of the int
 */
int my_intlen(int n)
{
	int len = 0;

	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}
