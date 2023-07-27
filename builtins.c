#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"
#include "lists.h"
#include "main.h"

/**
 * get_builtin - get built-in functn
 * @params: ptr to the param_t struct holdn cmd params
 * Return: Funct ptr to built-in funct. NULL if not found.
 */

void (*get_builtin(param_t *params))(param_t *)
{
    op_t ops[] = {
        {"exit", _myExit},
        {"clear", _clear},
        {"env", _printenv},
        {"setenv", _setenv},
        {"cd", _cd},
        {"unsetenv", _unsetenv},
        /*{"alias", _alias},*/
        {NULL, NULL},
    };
    op_t *op = ops;

    while (op->name)
    {
        if (!_strcmp(params->args[0], op->name))
            return (op->func);
        op++;
    }
    return (NULL);
}