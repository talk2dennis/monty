#include "monty.h"


/**
 * _push - pushes an element to the stack
 *
 * @stack: head of the linked list
 * @line: line number
 * Return: no return
 */
void _push(stack_t **stack, unsigned int line)
{
	int i, n;

	if (glo_var.arg == NULL)
	{
		fprintf(stderr, "L%u: ", line);
		fprintf(stderr, "usage: push integer\n");
		free_glo();
		exit(EXIT_FAILURE);
	}

	for (i = 0; glo_var.arg[i] != '\0'; i++)
	{
		if (!isdigit(glo_var.arg[i]) && glo_var.arg[i] != '-')
		{
			fprintf(stderr, "L%u: ", line);
			fprintf(stderr, "usage: push integer\n");
			free_glo();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(glo_var.arg);

	if (glo_var.lifo == 1)
		add_dnodeint(stack, n);
	else
		add_dnodeint_end(stack, n);
}

/**
 * _pall - prints all values on the stack
 * @stack: head of the linked list
 * @line: line numbers
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line)
{
	stack_t *tmp;
	(void) line;

	tmp = *stack;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 *
 * @stack: head of the linked list
 * @line: line number
 * Return: no return
 */
void _pint(stack_t **stack, unsigned int line)
{
	(void) line;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: ", line);
		fprintf(stderr, "can't pint, stack empty\n");
		free_glo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}




/**
 * _strtok - A function that splits a string into tokens
 * @s: string
 * @d: delimiters
 * Return: string
 */
char *_strtok(char *s, char *d)
{
	static char *ultimo;
	int i = 0, j = 0;

	if (!s)
		s = ultimo;
	while (s[i] != '\0')
	{
		if (_strch(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			s = s + j;
			return (s);
		}
		else if (_strch(d, s[i]) == 0 && _strch(d, s[i + 1]) == 0)
			i++;
		else if (_strch(d, s[i]) == 0 && _strch(d, s[i + 1]) == 1)
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			ultimo++;
			s = s + j;
			return (s);
		}
		else if (_strch(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}


/**
 * _strch - A function that checks if a char in a string
 * @s: poiter to string
 * @c: char
 * Return: (1) if found (0) otherwise
 */

int _strch(char *s, char c)
{
	int cont = 0;

	while (s[cont] != '\0')
	{
		if (s[cont] == c)
		{
			break;
		}
		cont++;
	}
	if (s[cont] == c)
		return (1);
	else
		return (0);
}
