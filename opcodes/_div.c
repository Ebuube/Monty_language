#include "../monty.h"

/**
 * _div - divide the second top element of the stack by the top element
 * @stack: address of the pointer to the stack
 * @line_number: line number being executed
 *
 * Description: The result is stored in the second top element of the stack
 * and the top element is removed making the stack one element shorter
 * Return: nothing
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: _div: NULL passed as stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	/* Check if stack has up to limit-number of elements */
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;

	/* Check division by zero */
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	/* div data (n) of second node by that of the first node */
	tmp->n = tmp->n / tmp->prev->n;

	/* Delete first element */
	free(*stack);
	(*stack) = tmp;
	tmp->prev = NULL;
}
