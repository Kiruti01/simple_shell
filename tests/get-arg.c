#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * get_arg - Returns a formttd arg based on type specifier.
 *
 * @type: Type specifier indicating desired formattng ('c', 's', 'd', 'i',
 *         'b', 'r', 'R').
 * @...: Var num of args depending on the type specifier.
 *



 *    The supported type specifiers are:
 *   - 'c': Char arg passed as int and returned str.
 *   - 's': String arg is passed as char* returned as a str.
 *   - 'd' or 'i': Int arg is passed as int returned as a str
 *   - 'b': Int arg is passed as int and returned as a binary str
 *   - 'r': Str arg is passed as char* and returned as reversed str
 *   - 'R': Str arg is passed as char* and returned as a ROT13 str
 *
 * Return: A dynamically allocated str repn of the arg based
 *        on the type specifier,
 *         or NULL if an unsupported type specifier is provided.
 */


char *get_arg(char type, ...)
{
	va_list params;

	va_start(params, type);
	switch (type)
	{
	case 'c':
		return (get_char(va_arg(params, int)));
	case 's':
		return (get_string(va_arg(params, char*)));
	case 'd':
	case 'i':
		return (get_number(va_arg(params, int)));
	case 'b':
		return (get_binary(va_arg(params, int)));
	case 'r':
		return (get_rev(va_arg(params, char *)));
	case 'R':
		return (get_rot13(va_arg(params, char *)));
	default:
		return (NULL);
		/* Error */
	}
}
