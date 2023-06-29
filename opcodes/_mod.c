#include "../monty.h"

/**
 * _mod - compute the rest of the division of the second top element
 * @stack: address of the pointer to the stack
 * @line_number: line number being executed
 *
 * Description: The result is stored in the second top element of the stack
 * and the top element is removed making the stack one element shorter
 * This is the same as modular arithmetic
 * Return: nothing
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	size_t limit = 2;	/* required number of elements */

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: _mod: NULL passed as stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	/* Check if stack has up to limit-number of elements */
	tmp = get_node_at((*stack), limit);
	if (tmp == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	/* Check division by zero */
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	/* data (n) of second node modulo data (n) of first node */
	tmp->n = tmp->n % tmp->prev->n;

	/* Delete first element */
	free(*stack);
	(*stack) = tmp;
	tmp->prev = NULL;
}
