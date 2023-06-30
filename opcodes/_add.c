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
	size_t i = 0;	/* iterator */

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: _add: NULL passed as stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	/* Check if stack has up to 2 elements */
	for (i = 0, tmp = (*stack); tmp != NULL && i < 2; i++)
	{
		tmp = tmp->next;
	}
	if (tmp == NULL && i < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	/* We are at the third node in the list, which can be NULL */
	tmp = tmp->prev;	/* step one node back to make a swap */

	/* add data (n) of first two nodes */
	tmp->n = tmp->n + tmp->prev->n;

	/* Delete first element */
	free(*stack);
	(*stack) = tmp;
	tmp->prev = NULL;
}
