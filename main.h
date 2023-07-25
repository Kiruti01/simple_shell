#ifndef _MAIN_H_
#define _MAIN_H_
#define NULL_PTR -1
#define WRONG_SPECIFIER -2

/**
 * get_char - puts a char into a memblock allocated using malloc
 * The allocated mem should has two bytes: the character, and the
 * terminating null byte.
 *
 * @c: character
 *
 * Return: pointer to that memblock, NULL if error
 */
char *get_char(char c);

/**
 * get_string - put a str int a mem block allocated using malloc
 * @s: string
 *
 * Return: pointer to that mem blck, NULL if error
 */
char *get_string(char *s);

/**
 * put_number - put an int into a block of mem
 * @n: integer
 *
 * Return: pointer to that mem block, NULL if error
 */
char *get_number(int n);

/**
 * print_arg - put one passed in param into a block of mem
 * @type: type of the param
 *
 * Return: pointer to the mem block, NULL if error
 */
char *get_arg(char type, ...);

/**
 * get_binary - converts an unsigned int to bin
 * @n: integer
 *
 * Return: pointer to bin
 */
char *get_binary(unsigned int n);

/**
 * get_rev - reverse a str
 * @s: string
 * Return: string reversed
 */
char *get_rev(char *s);

/**
 * get_rot13 - rot13 as a str
 * @s: string
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
