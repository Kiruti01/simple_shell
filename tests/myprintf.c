#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include <stdarg.h>

#define BUFFER_SIZE 1024

int flush_buffer(char *buffer, int *index);

int print_arg(char *arg);

void get_type(char *format, int *index);


/**
 * _printf - output text to standard output specified by format
 * @format: directives for outputting text
 *
 * Return: number of characters output
 */



int _printf(const char *format, ...)
{
	size_t high = 0, sum = 0, index = 0;
	char *arg = NULL;
	char buffer[BUFFER_SIZE] = {0};
	va_list params;

	if (!format)
		return (-1);
/*secial case only one % sign*/
	if (_strlen(format) == 1 && format[0] == '%')
	{
		return (-1);
	}

	va_start(params, format);
	while (1)
	{
		if (index == BUFFER_SIZE)
		{
			sum += flush_buffer(buffer, &index);
		}
		if (format[high] == '%')
		{
			get_type(format, &high);
			switch (format[high])
			{
			case 'c':
				buffer[index] = (char) va_arg(params, int);
				index++;
				high++;
				continue;
			case 's':
				arg = get_arg('s', va_arg(params, char*));
				break;
			case 'd':
			case 'i':
				arg = get_arg('d', va_arg(params, int));
				break;
			case 'b':
				arg = get_arg('b', va_arg(params, int));
				break;
			case 'r':
				arg = get_arg('r', va_arg(params, char *));
				break;
			case 'R':
				arg = get_arg('R', va_arg(params, char *));
				break;
			case '%':
				arg = malloc(2);
				arg[0] = '%';
				arg[1] = '\0';
				break;
			case '\0':
				buffer[index] = '%';
				index++;
				continue;
			default:
				arg = malloc(3);
				arg[0] = '%';
				arg[1] = format[high];
				arg[2] = '\0';
			}
			if (!arg)
			{
				va_end(params);
				free(arg);
				return (-1);
			}
			sum += flush_buffer(buffer, &index);
			sum += print_arg(arg);
			free(arg);
			high++;
		}
		else if (format[high] != '\0')
		{
			buffer[index] = format[high];
			index++;
			high++;
		}
		else
		{
			sum += flush_buffer(buffer, &index);
			va_end(params);
			return (sum);
		}
	}
	return (sum);
}
/**
 * flush_buffer - output out buffer upto index and reset
 * @buffer: buffer string
 * @index: index
 *
 * Return: total num of characters printed
 */
int flush_buffer(char *buffer, int *index)
{
	int num = 0;

	num = write(1, buffer, *index);
	*index = BUFFER_SIZE - 1;
	while (*index >= 0)
	{
		buffer[*index] = 0;
		*index -= 1;
	}
	*index = 0;
	return (num);
}
/**
 * print_arg - prnt arg str
 * @arg: str
 *
 * Return: number of bytes printed
 */
int print_arg(char *arg)
{
	return (write(1, arg, _strlen(arg)));
}
/**
 * get_type - get type from speccified form format string
 * @format: format string
 * @index: current index of format string
 */
void get_type(char *format, int *index)
{
	do {
		*index += 1;
	} while (format[*index] == ' ');
}