#include "monty.h"

/**
 * _sub - A functin that subtracts the top element from the second of the stack
 * @stack: pointer head the linked list
 * @line: int line
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line)
{
	int i;
	stack_t *tmp = NULL;

	tmp = *stack;

	for (i = 0; tmp != NULL; tmp = tmp->next, i++)
		;

	if (i < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line);
		free_glo();
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	tmp->n -= (*stack)->n;
	_pop(stack, line);
}


/**
 * _add - A function that adds the top two elements of the list
 * @stack: pointer to the list
 * @line: int;
 * Return: void
 */
void _add(stack_t **stack, unsigned int line)
{
	int i;
	stack_t *tmp = NULL;

	tmp = *stack;

	for (i = 0; tmp != NULL; tmp = tmp->next, i++)
		;

	if (i < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line);
		free_glo();
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	tmp->n += (*stack)->n;
	_pop(stack, line);
}

/**
 * _nop - A function that does nothing
 * @stack: pointer to the list
 * @line: int;
 * Return: nothing
 */

void _nop(stack_t **stack, unsigned int line)
{
	(void) line;
	(void) stack;
}

/**
 * _pstr - A function that prints string from anscii value
 * @stack: pointer the stack_t list
 * @line: int file line number
 * Return: nothing
 */


void _pstr(stack_t **stack, unsigned int line)
{
	stack_t *tmp;
	(void) line;

	tmp = *stack;
	while (tmp && tmp->n > 0 && (*stack)->n < 128)
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");
}

