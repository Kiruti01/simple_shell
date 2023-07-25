#include <unistd.h>
/**
 * sigint_handler - handle and terminate signal
 * @s: signal num
 */
void sigint_handler(int __attribute__((unused)) s)
{
	write(1, "\n($) ", 5);
}

