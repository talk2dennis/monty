#include "monty.h"

/**
 * get_opcodes - A function to get the opcode function
 * @opcode: pointer to strings
 * Return: Returns a pointer to functions
 */

void (*get_opcodes(char *opcode))(stack_t **stack, unsigned int line)
{
	instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"nop", _nop},
		{"queue", _queue},
		{"stack", _stack},
		{"pop", _pop},
		{"swap", _swap},
		{"queue", _queue},
		{"add", _add},
		{"sub", _sub},
<<<<<<< HEAD
		{"pchar", _pchar},
=======
		{"mul", _mul},
		{"mod", _mod},
		{"div", _div},
>>>>>>> 8218c82f17d6c9da6ea0821987e6e2d133665587
		{NULL, NULL}
	};
	int i;

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			break;
	}
	return (instructions[i].f);
}
