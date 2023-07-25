#ifndef _MAIN_H_
#define _MAIN_H_

#define NULL_PTR -1
#define WRONG_SPECIFIER -2

/**
 * gt_chr - Allocate memory for a character using malloc
 * The allocated memory should have two bytes: the character, and the
 * terminating null byte.
 *
 * @c: Character to be stored
 *
 * Return: Pointer to the allocated memory block, NULL if error
 */
char *gt_chr(char c);

/**
 * gt_str - Allocate memory for a string using malloc
 * @s: String to be stored
 *
 * Return: Pointer to the allocated memory block, NULL if error
 */
char *gt_str(char *s);

/**
 * pt_num - Allocate memory and store an integer
 * @n: Integer to be stored
 *
 * Return: Pointer to the allocated memory block, NULL if error
 */
char *pt_num(int n);

/**
 * pr_arg - Allocate memory for a passed parameter
 * @type: Type of the parameter (e.g., character, string, integer, etc.)
 *
 * Return: Pointer to the allocated memory block, NULL if error
 */
char *pr_arg(char type, ...);

/**
 * gt_bin - Convert an unsigned integer to binary
 * @n: Integer to be converted
 *
 * Return: Pointer to the binary representation as a string
 */
char *gt_bin(unsigned int n);

/**
 * rv_str - Reverse a string
 * @s: String to be reversed
 *
 * Return: Pointer to the reversed string
 */
char *rv_str(char *s);

/**
 * gt_r13 - Convert a string to Rot13
 * @s: String to be converted
 *
 * Return: Pointer to the converted string (Rot13)
 */
char *gt_r13(char *s);

char *str_cat(char *, char *);

char *str_ncat(char *, char *, unsigned int);

int str_len(char *);

int pr_format(const char *, ...);

char *str_chr(char *s, char c);

int to_int(char *s);

int cmp_str(char *, char *);

int cmp_str_n(char *, char *, int n);

#endif /* _MAIN_H_ */

