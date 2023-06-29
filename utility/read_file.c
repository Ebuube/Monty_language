#include "../monty.h"

/**
 * read_file - read a bytecode file and execute the instructions in it
 * @stack: address of pointer to stack being manipulated
 * @fp_stream: the input stream
 *
 * Return: the stream that was just executed
 * Otherwise, NULL if any problem occurs
 */
FILE *read_file(UNUSED stack_t **stack, UNUSED FILE *fp_stream)
{
	char *arr_tokens[2] = {NULL, NULL};	/* tokens */
	char *cp_line = NULL;	/* character pointer to line */
	char *delim = " \n";	/* delimiters */
	unsigned int line_number = 1;	/* line number to read */
	size_t num_tokens = 2;	/* number of tokens to get */
	size_t len = 0;		/* length of characters to read */
	ssize_t nread = 0;	/* number of characters read */

	if (fp_stream == NULL)
	{
		fprintf(stderr, "Error: Invalid stream\n");
		exit(EXIT_FAILURE);
	}

	for (line_number = 1; ; line_number++)
	{/* Go through the file, line_number starts from 1 */
		nread = getline(&cp_line, &len, fp_stream);
		if (nread == -1)
		{/* End of file */
			break;
		}
		/* Note: `cp_line` is modified by the parse_line() */
		if (parse_line(arr_tokens, num_tokens, delim, cp_line) == 0)
			continue;	/* empty line */
		else
		{/* execute the instruction on the line */
			bytecode.opcode = arr_tokens[0];
			bytecode.opcode_arg = _strtoi(arr_tokens[1]);

			/* execution */
			execute(stack, line_number);
		}
	}
	free(cp_line);	/* clean up */
	return (fp_stream);
}
