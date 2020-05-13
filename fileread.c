#include "monty.h"

/**
 * reader - Reads a file from input
 * @file: File to read
 * Return: Nothing, function is void.
 */

void reader(char *file)
{
	FILE *stream;
	stack_t *STACK = NULL;
	unsigned int lineno = 1; /* Start at 1 */
	char *buffer = NULL;
	size_t size = 0;
	char *cmd = NULL;

	stream = fopen(file, "r");
	if (!stream)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	global.gfile = stream;

	while (getline(&buffer, &size, stream) != -1)
	{
		cmd = strtok(buffer, "\n \t");
		global.command = cmd;
		global.input = strtok(NULL, "\n \t");
		getopc(&STACK, cmd, lineno);
		lineno++;
	}
	gfree(&STACK);
	fclose(stream);
}
