#include "monty.h"

/**
 * pchar - Print the character at the top of the Stack
 * @STACK: The stack
 * @lineno: Line number (for errors)
 * Return: Nothing, function is void
 */

void pchar(stack_t **STACK, unsigned int lineno)
{
	if (!STACK || !*STACK)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", lineno);
		gfree(STACK);
		exit(EXIT_FAILURE);
	}

	if (!isascii((*STACK)->n))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", lineno);
		gfree(STACK);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*STACK)->n);
}
