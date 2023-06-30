#include "../monty.h"

/**
 * _pstr - print the string starting at the top of the stack, followed
 * by a new line
 * @stack: address of the pointer to the stack
 * @line_number: line number being executed
 *
 * Description: The integer stored in each element of the stack is treated
 * as the ASCII value of the character to be printed.
 * The string stops when either ->
 * the stack is over,
 * the value of the element is 0
 * the value of the element is not in the ASCII table
 *
 * If the stack is empty, prints only a new line
 *
 * Return: nothing
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	int ascii_start = 0;	/* start of range of ASCII characters */
	int ascii_end = 127;	/* end of range of ASCII characters */

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: _pstr: NULL passed as stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	for (tmp = (*stack); (tmp != NULL) && (tmp->n != 0); tmp = tmp->next)
	{
		if ((ascii_start < tmp->n) && (tmp->n <= ascii_end))
			printf("%c", tmp->n);	/* print character */
		else
		{
			break;
		}
	}

	printf("\n");	/* terminating new line*/
}
