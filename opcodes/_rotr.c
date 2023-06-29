#include "../monty.h"

/**
 * _rotr - rotates the stack to the bottom
 * @stack: address of the pointer to the stack
 * @line_number: line number being executed
 *
 * Description: The last element of the stack becomes the first one
 *
 * Return: nothing
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: _rotr: NULL passed as stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack) == NULL || (*stack)->next == NULL)
	{/* Number of elements less than two - do nothing */
		return;
	}

	for (tmp = (*stack); tmp->next != NULL; tmp = tmp->next)
		;	/* get to the last node */

	/* Unplug and rejoin nodes */
	tmp->prev->next = NULL;
	tmp->next = (*stack);
	(*stack)->prev = tmp;

	(*stack) = tmp;		/* maintain the new top node */
}
