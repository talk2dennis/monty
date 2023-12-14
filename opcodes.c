#include "monty.h"

/**
 * opcodes - A function to get the opcode function
 * @opcode: pointer to strings
 * Return: Returns a pointer to functions
 */

void (*get_opcodes(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (strcmp(instruct[i].opcode, opcode) == 0)
			break;
	}

	return (instruct[i].f);
}
