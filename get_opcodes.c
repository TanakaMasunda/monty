#include "monty.h"

/**
 * get_opcodes - selects the correct stack opcode to perform
 * @opc: opcode passed
 * Return: pointer to the function that executes the opcode
 */

void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", _push}, /* to add to the stack */
		{"pall", _pall},
		{"pint", _pint}, /*  prints the value at the top of the stack */
		{"pop", _pop}, /* removes a node from the stack */
		{"swap", _swap}, /* swaps the to 2 elements in a stack */
		{"queue", _queue},
		{"stack", _stack},
		{"add", _add}, /* adds the top two elements of the stack. */
		{"nop", _nop}, /* doesnt do anything */
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (_strcmp(instruct[i].opcode, opc) == 0)
			break;
	}
	return (instruct[i].f);
}
