#include "monty.h"

/**
 * mod - Mod the top 2 nodes of the Stack, and removes the head
 * @STACK: The stack
 * @lineno: Line number (for errors)
 * Return: Nothing, function is void.
 */

void mod(stack_t **STACK, unsigned int lineno)
{
	stack_t *temp;

	if (!STACK || !*STACK || !(*STACK)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", lineno);
		gfree(STACK);
		exit(EXIT_FAILURE);
	}

	if ((*STACK)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", lineno);
		gfree(STACK);
		exit(EXIT_FAILURE);
	}

	temp = *STACK;

	temp->next->n = temp->next->n % temp->n;
	*STACK = temp->next;

	free(temp);
}
