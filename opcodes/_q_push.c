#include "../monty.h"

/**
 * _q_push - add a node to the last element of the queue
 * @stack: address of the pointer to the stack
 * @line_number: line number to execute
 *
 * Description: Generates error and exits if unsuccessful
 * Return: nothing
 */
void _q_push(UNUSED stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *new = NULL;	/* new node */
	stack_t *tmp = NULL;

	if (stack  == NULL)
	{
		return;
	}
	if (bytecode.opcode_arg == INT_MIN)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{/* Malloc failure */
		fprintf(stderr, "Error: malloc failure\n");
		exit(EXIT_FAILURE);
	}
	new->n = bytecode.opcode_arg;	/* assign values */
	new->prev = new->next = NULL;	/* Initialize pointers */

	/* link node */
	if ((*stack) == NULL)
	{/* For empty queue */
		(*stack) = new;
		return;
	}

	for (tmp = (*stack); tmp->next != NULL; tmp = tmp->next)
		;	/* get to the last node */

	tmp->next = new;
	new->prev = tmp;
	new->next = NULL;
}
