#include "../monty.h"

/**
 * _queue - set the format of the data to a queue (LIFO)
 * @stack: address of pointer to the queue
 * @line_number: line number being executed
 *
 * Return: nothing
 */
void _queue(UNUSED stack_t **stack, UNUSED unsigned int line_number)
{
	bytecode.state = FIFO;	/* First In, First Out - queue */
}
