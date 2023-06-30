#include "../monty.h"

/**
 * _stack - set the format of the data to a stack (LIFO)
 * @stack: address of pointer to the stack
 * @line_number: line number being executed
 *
 * Return: nothing
 */
void _stack(UNUSED stack_t **stack, UNUSED unsigned int line_number)
{
	bytecode.state = LIFO;	/* Last In, First Out - for stack */
}
