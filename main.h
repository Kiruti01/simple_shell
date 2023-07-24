#ifndef _MAIN_H_
#define _MAIN_H_
#define NULL_PTR -1
#define WRONG_SPECIFIER -2

/**
 * get_char - put a character into a memory block allocated using malloc
 * 
 * @c: character
 *
 * Return: pointer to that memory block, NULL if error
 */
char *get_char(char c);

/**
 * get_string - put str into a memblock allocated using malloc
 * @s: string
 * Return: pointer to that memory block, NULL if error
 */
char *get_string(char *s);

/**
 * put_number - put int into block of mem
 * @n: integer
 * Return: pointer to mem block, NULL if error
 */
char *get_number(int n);

/**
 * print_arg - put one passed in param into a block of mem
 * @type: type of the param
 * Return: pointer memblock, NULL if error
 */
char *get_arg(char type, ...);

/**
 * get_binary - convts an unsigned int to bin
 * @n: integer
 *
 * Return: pointer to bin
 */
char *get_binary(unsigned int n);

/**
 * get_rev - reverse a str
 * @s: string
 * Return: str reversed
 */
char *get_rev(char *s);

/**
 * get_rot13 - rot13 as a str
 * @s: str
 * Return: rot13
 */
char *get_rot13(char *s);

char *str_concat(char *, char *);

char *string_nconcat(char *, char *, unsigned int);

int _strlen(char *);

int _printf(const char *, ...);

char *_strchr(char *s, char c);

int _atoi(char *s);

int _strcmp(char *, char *);

int _strcmp_n(char *, char *, int n);


#endif
