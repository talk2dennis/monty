#include "monty.h"
/**
 * _pop - A function that deletes the last node on the list
 * @stack: pointer to the linked list
 * @line: int
 * Return: nothing
 */

void _pop(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	if (*stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
		free_glo();
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

/**
 * _swap - swaps the top two elements of the stack
 * @stack: head of the linked list
 * @line: line number
 * Return: no return
 */

void _swap(stack_t **stack, unsigned int line)
{
	int i;
	stack_t *tmp = *stack;

	for (i =0; tmp != NULL; tmp = tmp->next, i++)
		;

	if (i < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line);
		free_glo();
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
	(*stack)->prev = NULL;
}

#include "monty.h"

/**
 * _queue - updates the global variable to 1 (FIFO)
 * @stack: pointer to the linked list
 * @line: int line;
 * Return: nothing
 */

void _queue(stack_t **stack, unsigned int line)
{
	(void) stack;
	(void) line;

	glo_var.lifo = 0;
}

/**
 * _stack - updates the global variable to 1 (LIFO)
 *
 * @stack: pointer to the linked list
 * @line: int number;
 * Return: void
 */

void _stack(stack_t **stack, unsigned int line)
{
	(void) stack;
	(void) line;

	glo_var.lifo = 1;
}

