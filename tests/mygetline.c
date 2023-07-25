#include <unistd.h>
#include <stdlib.h>
#include "shell.h"
#include "main.h"
#define BUFFER_SIZE 4096
#define READ_SIZE 1024

/**
 * rlLine - realloc line buffer
 * @line: tob buffered
 * @oldSize: somtng borrowed
 * @newSize: somtng blue
 *
 * Return: new allocated buffer
 */
char *rlLine(char **line, size_t oldSize, size_t newSize)
{
	char *newLine = NULL;

	if (newLine)
	{
		for (size_t i = 0; i < oldSize; i++)
			newLine[i] = (*line)[i];
		free(*line);
		*line = newLine;
	}
	return (newLine);
}
/**
 * _getline - fetches line of chars from stdin
 * @params: params
 *
 * Return: number of char read
 */
int _getline(param_t *params)
{
	char *line = NULL;
	static size_t bufSize = BUFFER_SIZE;
	char *writeHead = line;
	size_t len;

	line = malloc(BUFFER_SIZE);
	if (!line)
		return (-1);

	do {
		len = read(0, writeHead, BUFFER_SIZE);
		if (len == 0)
			break;
		writeHead += len;
		if (writeHead >= (line + BUFFER_SIZE - 1 - READ_SIZE))
		{
			line = rlLine(&line, bufSize, bufSize * 2);
			bufSize *= 2;
		}
	} while (*(writeHead - 1) != '\n');

	free(params->buffer);
	params->buffer = line;

	if (len == 0)
		return (-1);
	return (_strlen(params->buffer));
}
