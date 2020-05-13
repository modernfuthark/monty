#include "monty.h"

/**
 * pall - Print stack
 * @STACK: The Stack
 * @lineno: Line number (for errors)
 * Return: Nothing, function is void.
 */

void pall(stack_t **STACK, unsigned int lineno)
{
	stack_t *temp;

	(void)lineno;

	if (!*STACK)
		return;
	temp = *STACK;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
