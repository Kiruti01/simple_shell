#include "main.h"
#include <stdlib.h>
void rev_string(char *s)
{
	int head, tail;
	int len;
	char tmp;

	if (s == NULL)
	{
		s = "(null)";
	}
	for (len = 0; s[len] != '\0'; len++)
		;
	head = 0;
	tail = len - 1;
	while (head < tail)
	{
		tmp = *(s + head);
		*(s + head) = *(s + tail);
		*(s + tail) = tmp;
		head++;
		tail--;
	}
}
