#include "monty.h"

/**
 * gfree - Global free, free the stack
 * @STACK: Stack
 * Return: Nothing, function is void.
 */

void gfree(stack_t **STACK)
{
	stack_t *temp;

	if (!STACK)
		return; /* No stack exists yet, ignore */
	/* Free global struct */
	free(global.command);
	free(global.input);

	while (*STACK)
	{
		temp = (*STACK)->next;
		free(*STACK);
		*STACK = temp;
	}
}

/**
 * main - Main entrance
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: EXIT_SUCCESS
 */

int main(int argc, char *argv[])
{
	(void) argv; /*Not used yet!!*/
	if (argc != 2) /*Not enough or too many arguments */
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	reader(argv[1]);
	exit(EXIT_SUCCESS);
}
