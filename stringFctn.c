#include <stdlib.h>

char *my_strcpy(char *dest, const char *src)
{
	int i = 0;

	if (dest == src || src == NULL)
		return (dest);

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];

		if (i >= SIZE - 1)
			break;
	}
	dest[i] = '\0';
	return (dest);
}
