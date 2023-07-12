#include <stdio.h>

/**
 * main - prints all the numbers of base 16 in lowercase,
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;
	char ch;

	for (n = 48; n < 58; n++)
	{
		write(n);
	}
	for (ch = 'a'; ch <= 'f'; ch++)
	{
		write(ch);
	}
	write('\n');
	return (0);
}
