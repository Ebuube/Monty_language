#include "../monty.h"

/**
 * free_stack - free a stack list
 * @stack: address of pointer to stack
 *
 * Return: nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *tracker = NULL;	/* To avoid infinite loop */
	stack_t *tmp = NULL;		/* Iterator */

	if (stack == NULL)
	{
		fprintf(stderr, "free_stack: Invalid address as stack\n");
		exit(EXIT_FAILURE);
	}

	for (tracker = tmp = (*stack)->next; tmp != NULL; tmp = tmp->next)
	{
		if ((*stack) != NULL)
			free((*stack));

		(*stack) = tmp;
		if (tracker == tmp->next)
		{
			fprintf(stderr, "free_stack: loop in stack\n");
			exit(EXIT_FAILURE);
		}
	}
	free((*stack));

	(*stack) = NULL;	/* Avoid dereferencing invalid address */
}
