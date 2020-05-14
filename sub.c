#include "monty.h"

/**
 * sub - Subtract the top 2 nodes of the Stack, and removes the head
 * @STACK: The stack
 * @lineno: Line number (for errors)
 * Return: Nothing, function is void.
 */

void sub(stack_t **STACK, unsigned int lineno)
{
	stack_t *temp;

	if (!STACK || !*STACK || !(*STACK)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", lineno);
		gfree(STACK);
		exit(EXIT_FAILURE);
	}

	temp = *STACK;

	temp->next->n = temp->next->n - temp->n;
	*STACK = temp->next;

	free(temp);
}
