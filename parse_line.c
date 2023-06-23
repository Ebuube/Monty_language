#include "monty.h"

/**
 * parse_line - split a line into an array of 'space' delimited strings
 * @arr_buffer: An array of pointers.
 * @buf_size: The size of the array.
 * @cp_line: a null terminated string to split
 *
 * Return: the number of tokens obtained from cp_line
 */
size_t parse_line(UNUSED char *arr_buffer[], UNUSED size_t buf_size,
		UNUSED char *cp_line)
{
	UNUSED char *saveptr = NULL;	/* For strtok_r() function */
	UNUSED char *delim = " ";	/* space as a delimiter */
	UNUSED char *token = NULL;	/* For saving the token fetched */
	UNUSED size_t num_tokens = 0;	/* tokens to from the line string */

	if (arr_buffer == NULL || buf_size < 2)
	{
		fprintf(stderr,
			"Error: arr_buffer is NULL or buff_size < 2\n");
		exit(EXIT_FAILURE);
	}

	for (num_tokens = 0; num_tokens < buf_size;
			cp_line = NULL, num_tokens++)
	{
		token = strtok_r(cp_line, delim, &saveptr);
		arr_buffer[num_tokens] = token;
		if (token == NULL)
		{/* No more tokens */
			/* fprintf(stderr, "token is NULL\n");	 test */
			break;
		}
	}

	/* if no opcode was received, return 0 */
	num_tokens = ((arr_buffer[0] == NULL ||
				strcmp(arr_buffer[0], "\n") == 0) &&
			num_tokens == 1) ? 0 : num_tokens;

	return (num_tokens);
}
