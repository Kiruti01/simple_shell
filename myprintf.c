#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

#define BUFFER_SIZE 1024

int flush_buffer(char *buffer, int *index);

int print_arg(char *arg);
