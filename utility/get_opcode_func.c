#include "../monty.h"

/**
 * get_opcode_func - finds appropriate opcode function
 *
 * Return: address of opcode function else NULL if not found
 */
opcode_func *get_opcode_func(void)
{
	size_t i = 0;
	char comment_starter = '#';

	instruction_t funcs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{NULL, NULL}
	};

	for (i = 0; funcs[i].opcode != NULL; i++)
	{
		if (strcmp(bytecode.opcode, funcs[i].opcode) == 0)
		{
			return (funcs[i].f);
		}
	}

	if (bytecode.opcode[0] == comment_starter)
	{/* Do nothing for the comment_starter */
		for (i = 0; funcs[i].opcode != NULL; i++)
		{
			if (strcmp(funcs[i].opcode, "nop") == 0)
			{
				return (funcs[i].f);
			}
		}
	}

	return (NULL);
}
