#include "monty.h"


/**
 * _push - pushes an element to the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _push(stack_t **doubly, unsigned int cline)
{
	int n, j;

	if (glo_var.arg == NULL)
	{
		fprintf(stderr, "L%u: ", cline);
		fprintf(stderr, "usage: push integer\n");
		free_glo();
		exit(EXIT_FAILURE);
	}

	for (j = 0; glo_var.arg[j] != '\0'; j++)
	{
		if (!isdigit(glo_var.arg[j]) && glo_var.arg[j] != '-')
		{
			fprintf(stderr, "L%u: ", cline);
			fprintf(stderr, "usage: push integer\n");
			free_glo();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(glo_var.arg);

	if (glo_var.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}

/**
 * _pall - prints all values on the stack
 * @doubly: head of the linked list
 * @cline: line numbers
 * Return: void
 */
void _pall(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _pint(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		fprintf(stderr, "L%u: ", cline);
		fprintf(stderr, "can't pint, stack empty\n");
		free_glo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
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
