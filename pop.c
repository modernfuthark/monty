#include "monty.h"

/**
 * pop - Pop the top node of STACK
 * @STACK: The stack
 * @lineno: Line number (for errors)
 * Return: Nothing, function is void.
 */

void pop(stack_t **STACK, unsigned int lineno)
{
	stack_t *temp;

	if (!STACK || !*STACK)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", lineno);
		gfree(STACK);
		exit(EXIT_FAILURE);
	}

	temp = (*STACK)->next;
	free(*STACK);
	*STACK = temp;
	if (!*STACK)
		return;
	(*STACK)->prev = NULL;
}
