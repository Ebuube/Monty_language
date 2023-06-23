#include "monty.h"

/**
 * execute - execute an opcode on the stack
 * @arr_opcode_arg: A two element array of opcode and its argument
 * @line_number: The line being executed
 *
 * Return: 0 if successful, else, 1
 */
int execute(UNUSED char *arr_opcode_arg[], UNUSED size_t line_number)
{
	if (arr_opcode_arg == NULL)
	{/* Invalid array */
		fprintf(stderr,
			"ERROR: NULL instruction passed to be executed\n");
		return (1);
	}

	/* test */
	printf("L%lu:\t|\topcode: %s\t|\targ: %s\n",
		line_number, arr_opcode_arg[0], arr_opcode_arg[1]);
	return (0);
}
