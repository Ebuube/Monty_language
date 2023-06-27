#include "../monty.h"

/**
 * _swap - swap the top two elements of the stack.
 * @stack: address of the pointer to the stack
 * @line_number: line number being executed
 *
 * Description: Generates error and exits if unsuccessful
 * Return: nothing
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	size_t i = 0;	/* iterator */

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: _pall: NULL passed as stack\n",
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
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	/* We are at the third node in the list, which can be NULL */
	tmp = tmp->prev;	/* step one node back to make a swap */

	/* swap nodes */
	(*stack)->prev = tmp;
	(*stack)->next = tmp->next;
	tmp->prev = NULL;
	tmp->next = (*stack);

	if ((*stack)->next != NULL)
		(*stack)->next->prev = (*stack);

	(*stack) = tmp;		/* Reassign head pointer to stack */
}
