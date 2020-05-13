#ifndef MONTY_H
#define MONTY_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

/* Structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct holder_s - Temp holder
 * @input: Number that is input
 * @command: Command
 * @gfile: Global file holder
 */

typedef struct holder_s
{
	/*int mode = 1;*/
	char *input;
	char *command;
	FILE *gfile;
} holder_t;

extern holder_t global;
holder_t global;

/* Function Prototypes */
void reader(char *file);
void getopc(stack_t **STACK, char *cmd, unsigned int lineno);
int numcheck(char *string);
void gfree(stack_t **STACK);

/* OP Codes */
void push(stack_t **STACK, unsigned int lineno);
void pall(stack_t **STACK, unsigned int lineno);
void pint(stack_t **STACK, unsigned int lineno);
void pop(stack_t **STACK, unsigned int lineno);
void swap(stack_t **STACK, unsigned int lineno);
void add(stack_t **STACK, unsigned int lineno);
void nop(stack_t **STACK, unsigned int lineno);

#endif
