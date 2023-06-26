#include "../monty.h"

/**
 * _pall - print all the values on the stack from the top of the stack
 * @stack: address of the pointer to the stack
 * @line_number: line number to execute
 *
 * Description: It ensures that it is not infinitely going in a circular list
 * Return: nothing
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tracker = NULL;	/* To avoid infinite loop */
	stack_t *tmp = NULL;	/* For printing the values */

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: _pall: NULL passed as stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack) == NULL)
	{/* Empty stack */
		return;
	}
	tmp = (*stack);
	tracker = (*stack);

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
		if (tmp == tracker)
		{
			fprintf(stderr, "L%u: _pall: loop in stack\n",
				line_number);
			exit(EXIT_FAILURE);
		}
	}
}
