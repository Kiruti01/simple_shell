#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * get_arg - Returns formatted arg on the type specifier.
 * @type: Type specifier indicating the desired formatting ('c', 's', 'd', 'i',
 *         'b', 'r', 'R').
 * @...: Variable num of args on the type specifier.
 *    Supported type specifiers;
 *   - 'c': Char arg is passed as int returned as a str
 *   - 's': Str arg is passed as char* returned as a str
 *   - 'd' or 'i': Int arg is passed as int returned as a str
 *   - 'b': Int arg is passed as int returned as a binary str
 *   - 'r': Str arg is passed as char* returned as reversed str
 *   - 'R': Str arg is passed as char* returned as a ROT13 str
 *
 * Return: Allocated str rep of arg based on type specifier,
 *         or NULL if unsupported type specifier provided.
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
	}
}
