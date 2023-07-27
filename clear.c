#include "main.h"
#include "shell.h"

/**
 * _clear - clears terminal
 * @params: parameters
 * Return: void
 */
void _clear(param_t *params)
{
    (void)params;
    _printf("\033[2J\033[1;1H");
}