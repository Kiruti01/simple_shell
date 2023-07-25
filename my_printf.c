#include "main.h"

/**
 * print_num - a function that prints unsigned int putchar
 * @n: unsnged int
 * return: void
 */
void print_num(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		print_num (x / 10);

		_putchar(x % 10 + '0');

}
/**
 * num_putchar - a fuction that prints number putchar
 * @n: input integer
 *return: void
 */
void num_putchar(int n)
{
	unsigned int k = n;

	if (n < 0)
	{
		_putchar('-');
		k = -k;
	}
	if ((k / 10) > 0)
		print_num (k / 10);
	_putchar(k % 10 + '0');
}

