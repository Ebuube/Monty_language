#include "../monty.h"

/**
 * _rotl - rotates the stack to the top
 * @stack: address of the pointer to the stack
 * @line_number: line number being executed
 *
 * Description: The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one
 *
 * Return: nothing
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	stack_t *second_top = NULL;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: _rotl: NULL passed as stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack) == NULL || (*stack)->next == NULL)
	{/* number of elements less than two - do nothing */
		return;
	}
	second_top = (*stack)->next;	/* Keep reference to the head node */

	for (tmp = (*stack); tmp->next != NULL; tmp = tmp->next)
		;	/* get to the last node */

	/* Unplug and rejoin nodes */
	(*stack)->next->prev = NULL;
	(*stack)->next = NULL;

	tmp->next = (*stack);
	(*stack)->prev = tmp;

	(*stack) = second_top;	/* maintain the new top node */
}
