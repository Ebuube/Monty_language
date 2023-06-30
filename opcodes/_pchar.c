#include "../monty.h"

/**
 * _pchar - prints the char at the top of the stack, followed by a new line
 * @stack: address of the pointer to the stack
 * @line_number: line number to execute
 *
 * Description: Note this function only prints a number in the range of
 * ASCII characters. i.e. 0 - 127 inclusive.
 * Return: nothing
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int ascii_start = 0;	/* start of range of ASCII characters */
	int ascii_end = 127;	/* end of range of ASCII characters */

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: _pchar: NULL passed as stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack) == NULL)
	{/* Empty stack */
		fprintf(stderr, "L%u: can't pchar, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	/* Check against invalid decimal value as ASCII character */
	if ((ascii_start <= (*stack)->n) && ((*stack)->n <= ascii_end))
		printf("%c\n", (*stack)->n);	/* print character */
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
			line_number);
		exit(EXIT_FAILURE);
	}
}
