#include "monty.h"

/**
 * opcodes - A function to get the opcode function
 * @opcode: pointer to strings
 * Return: Returns a pointer to functions
 */

void (*opcodes(char *opcode))(stack_t *stack, int line)
{
	int i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};

	for (i = 0; instructon[i].opcode; i++)
        {
                if (strcmp(opcode, instructions[i].opcode) == 0)
                        break;
        }

	return (instructions[i].f);

}
