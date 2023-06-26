#include "../monty.h"

/**
 * parse_line - split a line using delimiters and save them in the buffer
 * @arr_buffer: An array of pointers to feed the tokens
 * @buf_size: the size of the array
 * @delim: a string where each character is considered a delimiter
 * @cp_line: a null terminated string to split
 *
 * Return: the number of tokens obtained from cp_line
 */
size_t parse_line(char **arr_buffer, size_t buf_size, char *delim,
		char *cp_line)
{
	char *saveptr = NULL;	/* For strtok_r() function */
	char *token = NULL;	/* For saving the token fetched */
	size_t num_tokens = 0;	/* For iterating to get bu_size tokens */

	if (arr_buffer == NULL)
	{
		fprintf(stderr, "Error: arr_buffer is NULL\n");
		return (0);
	}
	if (cp_line == NULL)
	{
		fprintf(stderr, "Error: cp_line is NULL\n");
		return (0);
	}
	if (delim == NULL)
	{
		fprintf(stderr, "Error: delimiter is NULL\n");
		return (0);
	}

	for (num_tokens = 0; num_tokens < buf_size;
			cp_line = NULL, num_tokens++)
	{
		token = strtok_r(cp_line, delim, &saveptr);
		arr_buffer[num_tokens] = token;
		if (token == NULL)
		{/* No more tokens */
			break;
		}
	}
	/* if no opcode was received, return 0 */
	num_tokens = ((arr_buffer[0] == NULL ||
			strcmp(arr_buffer[0], "\n") == 0) &&
			num_tokens == 1) ? 0 : num_tokens;

	return (num_tokens);
}
