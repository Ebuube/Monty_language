#include "../monty.h"

/**
 * _pop - removes the top element of the stack
 * @stack: address of the pointer to the stack
 * @line_number: line number being executed
 *
 * Description: If the stack is empty, it exits with an error message
 * Return: nothing
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;	/* tracker */

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: _pall: NULL passed as stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack) == NULL)
	{/* Empty stack */
		fprintf(stderr, "L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	/* delete node */
	tmp = (*stack);
	(*stack) = (*stack)->next;
	free(tmp);

	if ((*stack) != NULL)	/* if stack is not empty */
		(*stack)->prev = NULL;
}
