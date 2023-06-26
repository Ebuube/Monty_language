#include "../monty.h"

/**
 * get_opcode_func - finds appropriate opcode function
 *
 * Return: address of opcode function else NULL if not found
 */
opcode_func *get_opcode_func(void)
{
	size_t i = 0;

	instruction_t funcs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{NULL, NULL}
	};

	for (i = 0; funcs[i].opcode != NULL; i++)
	{
		if (strcmp(bytecode.opcode, funcs[i].opcode) == 0)
		{
			return (funcs[i].f);
		}
	}

	return (NULL);
}
