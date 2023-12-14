#include "monty.h"

/**
 * _div - A function that multiplies the top two elements of the list
 * @stack: pointer to the list
 * @line: int;
 * Return: void
 */
void _div(stack_t **stack, unsigned int line)
{
	int i;
	stack_t *tmp = *stack;

	for (i = 0; tmp != NULL; tmp = tmp->next, i++)
		;
	if (i < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line);
		free_glo();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		free_glo();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	tmp->n /= (*stack)->n;
	_pop(stack, line);
}


/**
 * _mul - A function that multiplies the top two elements of the list
 * @stack: pointer to the list
 * @line: int;
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line)
{
	int i;
	stack_t *tmp = *stack;

	for (i = 0; tmp != NULL; tmp = tmp->next, i++)
		;
	if (i < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line);
		free_glo();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		free_glo();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	tmp->n *= (*stack)->n;
	_pop(stack, line);
}

/**
 * _mod - A function that multiplies the top two elements of the list
 * @stack: pointer to the list
 * @line: int;
 * Return: void
 */
void _mod(stack_t **stack, unsigned int line)
{
	int i;
	stack_t *tmp = *stack;

	for (i = 0; tmp != NULL; tmp = tmp->next, i++)
		;
	if (i < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line);
		free_glo();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		free_glo();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	tmp->n %= (*stack)->n;
	_pop(stack, line);
}
