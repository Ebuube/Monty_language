#include "../monty.h"

/**
 * _add - add the top two elements of the stack.
 * @stack: address of the pointer to the stack
 * @line_number: line number being executed
 *
 * Description: If the stack has less than 2 elements,
 * it exits with an error message
 * | Note | stack becomes one element shorter and the result of the
 * addition is found in the top element of the stack
 *
 * Return: nothing
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: _add: NULL passed as stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	/* Check if stack has up to limit-number of elements */
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;

	/* add data (n) of first two nodes */
	tmp->n = tmp->n + tmp->prev->n;

	/* Delete first element */
	free(*stack);
	(*stack) = tmp;
	tmp->prev = NULL;
}
