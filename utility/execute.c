#include "../monty.h"

/**
 * execute - execute the opcode on the stack
 * @stack: address of pointer to the stack_t list
 * @line_number: the line number being executed
 *
 * Return: 0 if successful, else 1
 */
int execute(stack_t **stack, unsigned int line_number)
{
	UNUSED opcode_func *func = NULL;	/* The operation to execute */

	if (stack == NULL)
	{/* NULL passed as stack */
		fprintf(stderr, "Error in execute: NULL passed as stack\n");
		return (1);
	}
	if (bytecode.opcode == NULL)
	{/* NULL passed as opcode */
		fprintf(stderr, "L%u: execute: NULL passed as opcode\n",
			line_number);
		return (1);
	}

	func = get_opcode_func();
	if (func == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, bytecode.opcode);
		exit(EXIT_FAILURE);
	}
	else
		func(stack, line_number);

	return (0);
}
