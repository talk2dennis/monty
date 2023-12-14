#include "monty.h"

global_t glo_var;

/**
 * free_glo - Free memory from the global variables
 * Return: void
 */
void free_glo(void)
{
	free_dlistint(glo_var.head);
	fclose(glo_var.file);
}

/**
 * init_glo - Initializes the global variables for the monty
 * @file: pointer to file
 * Return: void
 */
void init_glo(FILE *file)
{
	glo_var.lifo = 1;
	glo_var.line = 0;
	glo_var.arg = NULL;
	glo_var.head = NULL;
	glo_var.file = file;
}

/**
 * check_input - checks the input provided
 * @argc: int count
 * @argv: pointer to argurment
 * Return: pointer to file
 */

FILE *check_input(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (file);
}

/**
 * main - Entry point to our program monty
 * @argc: int count
 * @argv: pointer to argurment
 * Return: (0) on success or (1) on failure
 */

int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line);
	FILE *file;
	char *lines[2] = {NULL, NULL};

	file = check_input(argc, argv);
	init_glo(file);
	while (fgets(glo_var.buffer, sizeof(glo_var.buffer), file) != NULL) 
	{
		glo_var.line++;
		lines[0] = _strtok(glo_var.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				fprintf(stderr, "L%u: ", glo_var.line);
				fprintf(stderr, "unknown instruction %s\n", lines[0]);
				free_glo();
				exit(EXIT_FAILURE);
			}
			glo_var.arg = _strtok(NULL, " \t\n");
			f(&glo_var.head, glo_var.line);
		}
	}

	free_glo();

	return (EXIT_SUCCESS);
}
