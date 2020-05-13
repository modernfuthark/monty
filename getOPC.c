#include "monty.h"

/**
 * getopc - Get OPcode
 * @STACK: Stack structure
 * @cmd: Command
 * @lineno: Line number (For errors)
 * Return: Nothing, function is void
 */

void getopc(stack_t **STACK, char *cmd, unsigned int lineno)
{
	int i;
	instruction_t commands[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	if (cmd[0] == '#' || !cmd) /* izza comment or blank line */
		return;

	for (i = 0; commands[i].opcode; i++)
	{
		if (strcmp(commands[i].opcode, cmd) == 0)
		{
			commands[i].f(STACK, lineno);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", lineno, cmd);
	gfree(STACK);
	exit(EXIT_FAILURE);
}
