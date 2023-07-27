#ifndef _MAIN_H_
#define _MAIN_H_

/*Null ptr*/
#define NULL_PTR -1

/*specifier*/
#define WRONG_SPECIFIER -2

/**
 * get_char - puts char into a memblock allocated usn malloc
 * The allocated mem shd hv two bytes: char, and termntng nullbyte.
 * @c: character
 * Return: ptr to that memblock, NULL if error
 */
char *get_char(char c);

/**
 * get_string - put a str int a mem block allocated using malloc
 * @s: string
 * Return: ptr to that mem blck, NULL if error
 */
char *get_string(char *s);

/**
 * put_number - puts int into a block of mem
 * @n: integer
 * Return: ptr to that mem block, NULL if error
 */
char *get_number(int n);

/**
 * print_arg - put one passed in param into a block of mem
 * @type: type of param
 * Return: ptr to the mem block, NULL if error
 */
char *get_arg(char type, ...);

/**
 * get_binary - cnvts unsigned int to bin
 * @n: integer
 * Return: ptr to bin
 */
char *get_binary(unsigned int n);

/**
 * get_rev - reverse a str
 * @s: str
 * Return: str reversed
 */
char *get_rev(char *s);

/**
 * get_rot13 - rot13 as str
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