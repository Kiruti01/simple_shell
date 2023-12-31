#ifndef LISTSH
#define LISTSH

#include <unistd.h>

/**
 * struct list_s - singly lnked list node
 * @str: str data
 * @val: val str data
 * @len: len of str data
 * @valLen: len of val str data
 * @next: ptr to nxt node in the list
 */

typedef struct list_s
{
	char *str;
	char *val;
	unsigned int len;
	unsigned int valLen;
	struct list_s *next;
} list_t;

int _putchar(char c);

size_t print_list(list_t *h);

size_t list_len(list_t *h);

list_t *add_node(list_t **head, char *str, char *val);

void free_list(list_t *head);

list_t *get_node(list_t *head, char *str);

#endif
