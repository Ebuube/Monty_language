#include "../monty.h"

/**
 * _pint - print the value at the top of the stack, followed by a new line
 * @stack: address of the pointer to the stack
 * @line_number: line number to execute
 *
 * Description: If the stack is empty, exits with an error message
 * Return: nothing
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%u: _pint: NULL passed as stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack) == NULL)
	{/* Empty stack */
		fprintf(stderr, "L%u: can't pint, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);	/* print value */
}
