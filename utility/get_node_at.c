#include "../monty.h"

/**
 * get_node_at - finds the nth node in a stack_t list
 * @stack: a stack_t list to search
 * @n: the position of the node to fetch
 *
 * Description: The first node in the stack has a position of 1
 * Return: nth node, else NULL if not found
 */
stack_t *get_node_at(stack_t *stack, size_t n)
{
	if (stack == NULL)
	{/* Empty list */
		return (NULL);
	}

	for (; (stack != NULL) && (n > 1); n--)
	{
		stack = stack->next;
	}

	return (stack);
}
