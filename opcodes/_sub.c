#include "../monty.h"

/**
 * _sub - subtract the top element of the stack from the second top element
 * @stack: address of the pointer to the stack
 * @line_number: line number being executed
 *
 * Description: The result is stored in the second top element of the stack
 * and the top element is removed making the stack one element shorter
 *
 * Return: noting
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	size_t limit = 2;	/* required number of elements */

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: _sub: NULL passed as stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	/* Check if stack has up to limit-number of elements */
	tmp = get_node_at((*stack), limit);
	if (tmp == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	/* sub data (n) of first node from that of the second node */
	tmp->n = tmp->n - tmp->prev->n;

	/* Delete first element */
	free(*stack);
	(*stack) = tmp;
	tmp->prev = NULL;
}
