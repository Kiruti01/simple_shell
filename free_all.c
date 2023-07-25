#include "main.h"
/**
 * my_calloc -  Allocates memory for an array, using malloc.
 * @s: Size.
 * Return: Void Pointer.
 */
void *my_calloc(unsigned int s)
{
	char *k;
	unsigned int i;

	if (s == 0)
	return (NULL);
	k = malloc(s);
	if (k == NULL)
	return (NULL);
	for (i = 0; i < s; i++)
	{
		k[i] = '\0';
	}
	return (k);
}
/**
 * free_all - Frees the mem alloc for an array of char pointers (command)
 * @command: Array Pointer
 * @ptr: Char Pointer
 * Return: Nothing
 */
void free_all(char **command, char *ptr)
{
	free(command);
	free(ptr);
	command = NULL;
	ptr = NULL;
}
/**
 *_realloc - Reallocates a memory block using malloc and free
 *@ptr: Pointer
 *@i: Previous size of the pointer
 *@j: New size of the pointer
 *Return: Void pointer rellocated memory.
 */
void *my_realloc(void *ptr, unsigned int i, unsigned int j)
{
	void *new;

	if (j == i)
		return (ptr);
	if (j == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	new = malloc(j);

	if (new == NULL)
	{
		return (NULL);
	}
	if (ptr == NULL)
	{
		array_handler(new, '\0', j);
		free(ptr);
	}
	else
	{
		my_memcpy(new, ptr, i);
		free(ptr);
	}
	return (new);
}
/**
 * my_memcpy - Copies a num of bytes from a source ptr to a destn ptr.
 * @dest: Destn Pointer
 * @src: Source Pointer
 * @c: Size to be copied.
 *Return: Void Pointer
 */
char *my_memcpy(char *dest, char *src, unsigned int c)
{
	unsigned int i;

	for (i = 0; i < c; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * array_handler - Fills an array with a constant byte value.
 * @j: Void Pointer
 * @k: Int
 * @len: Length Int
 *Return: Void Pointer
 */
void *array_handler(void *j, int k, unsigned int len)
{
	char *index = j;
	unsigned int i = 0;

	while (i < len)
	{
		*index = k;
		index++;
		i++;
	}
	return (j);
}
