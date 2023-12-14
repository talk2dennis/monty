#include "monty.h"
#include <string.h>

char *split(char *str)
{
	int i = 0, len = strlen(str), op = 0, cd = 0;
	char opcode[100], instruct[100], *instruction = NULL;

	for (i = 0; i < len; i++)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= 'a' && str[i] <= 'z'))
		{
			opcode[op] = str[i];
			op++;
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			instruct[cd] = str[i];
			cd++;
		}
	}
	opcode[op] = '\0';
	instruct[cd] = '\0';
	
	instruction = malloc(sizeof(char) * strlen(opcode));
	if (instruction == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	strcpy(opcode, instruction);
	return (instruction);
}

/**
 * main - The main entrance to our function monty
 * @argc: int
 * @argv: pointer to the list of command argurment
 * Return: (1) on success otherwise (-1)
 */

int main(int argc, char **argv)
{
	void (*opcodes)(stack_t *stack, int line);
	char buffer[1024], *opcode = NULL;
	FILE *file = NULL;
	int line = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen (argv[1], "r");
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		line++;
		printf("%d: %s", line, buffer);
		opcode = split(buffer);
		opcodes = opcodes(opcode);
		opcodes(stack, line);
	}
	fclose(file);
	return(EXIT_SUCCESS);
}
