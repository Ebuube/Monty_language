#include "monty.h"

/**
 * read_file - read the instructions in a bytecode file
 * @stream: a file pointer to input stream
 *
 * Return: return 0 if successful else, exit with EXIT_FAILURE
 */
int read_file(FILE *stream)
{
	UNUSED char *arr_command[2] = {
		NULL, NULL
	};/* opcode and argument array */
	UNUSED char *cp_line = NULL;	/* character pointer to line */
	UNUSED size_t len = 0;		/* length of characters to read */
	UNUSED size_t buf_size = 2;	/* number of tokens to get */
	UNUSED size_t line_count = 0;	/* counts the line being executed */
	UNUSED ssize_t nread = 0;	/* number of characters read */

	if (!stream)
	{/* Invalid stream */
		fprintf(stderr, "Invalid stream to be executed\n");
		exit(EXIT_FAILURE);
	}

	for (line_count = 1; ; line_count++)/* must star from 1 */
	{/* Execute instructions */
		nread = getline(&cp_line, &len, stream);
		if (nread == -1)
		{/* End of file */
			break;
		}
		/* divide line into opcode and argument value */
		/* Note: `cp_line` is modified by the parse_line() */
		if (parse_line(arr_command, buf_size, cp_line) == 0)
			continue;	/* empty line */
		else	/* run opcode on Stack */
			execute(arr_command, line_count);
	}

	free(cp_line);	/* clean up */
	return (0);
}
/*
 *		================================================
 *			COMPLETE BY CREATING THE FUNCTION - 'execute'
 *			REPLACE THE NAME OF THIS FUNCTION TO - "read_file"
 *			MAKE THE CHANGE REFLECT IN OTHER FILES
 *
 *			THE 'execute' FUNCTION ACCEPTS TWO ARGUMENTS
 *			- THE OPCODE
 *			- AND THE ARGUMENT (IF ANY)
 *			THIS FUNCTION WILL IN TURN MAKE USE OF THE STACK
 *			AND CALL THE NECESSARY FUNCTION FOR EACH OPCODE
 *		-------------------------------------------------
 */
