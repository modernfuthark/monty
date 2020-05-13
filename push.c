#include "monty.h"

/**
 * numcheck - Check if input is a number
 * @string: String to check
 * Return: 0 on fail, 1 on success
 */

int numcheck(char *string)
{
	int i = 0;

	while (string[i])
	{
		if (!isdigit(string[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * push - Add node to stack
 * @STACK: Stack
 * @lineno: Line number (for errors)
 * Return: Nothing, function is void
 */

void push(stack_t **STACK, unsigned int lineno)
{
	stack_t *NEW;

	if (!numcheck(global.input))
	{
		fprintf(stderr, "L%u: usage: push integer\n", lineno);
		gfree(STACK);
		exit(EXIT_FAILURE);
	}

	NEW = malloc(sizeof(stack_t));
	if (!NEW)
	{
		fprintf(stderr, "Error: malloc failed\n");
		gfree(STACK);
		exit(EXIT_FAILURE);
	}

	/* Add to stack */
	NEW->n = atoi(global.input);
	if (!*STACK)
	{
		NEW->next = NULL;
		NEW->prev = NULL;
		*STACK = NEW;
	}
	else
	{
		(*STACK)->prev = NEW;
		NEW->next = *STACK;
		NEW->prev = NULL;
		*STACK = NEW;
	}
}
