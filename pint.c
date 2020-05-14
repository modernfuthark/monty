#include "monty.h"

/**
 * pint - Print the top of the stack
 * @STACK: The stack
 * @lineno: Line number
 */

void pint(stack_t **STACK, unsigned int lineno)
{
	if (!STACK || !*STACK)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", lineno);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*STACK)->n);
}
