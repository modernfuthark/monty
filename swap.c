#include "monty.h"

/**
 * swap - Swap the top 2 nodes of the Stack
 * @STACK: The stack
 * @lineno: Line number (for errors
 * Return: Nothing, function is void.
 */

void swap(stack_t **STACK, unsigned int lineno)
{
	stack_t *temp;
	int hold;

	if (!STACK || !*STACK || !(*STACK)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", lineno);
		gfree(STACK);
		exit(EXIT_FAILURE);
	}

	temp = *STACK;
	hold = temp->n;

	temp->n = temp->next->n;
	temp->next->n = hold;
}
