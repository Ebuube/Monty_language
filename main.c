#include "monty.h"

/**
 * main - Execute the monty program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0 if successful
 */
int main(UNUSED int argc, UNUSED char *argv[])
{
	UNUSED FILE *fp_file = NULL;	/* File pointer to input stream */
	UNUSED char *cp_filename = NULL;	/* pointer to filename */
	UNUSED char *mode = "r";	/* Mode for opening file */
	stack_t *stack = NULL;	/* Stack to manipulate */

	if (argc < 2)
	{/* Ensure file name was passed on command line */
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	cp_filename = argv[1];	/* set name of file to run */

	fp_file = fopen(cp_filename, mode);
	if (fp_file == NULL)
	{/* File doesn't exist */
		fprintf(stderr, "Error: Can't open file %s\n", cp_filename);
		exit(EXIT_FAILURE);
	}

	/* Execute instructions in the stream */
	read_file(&stack, fp_file);

	/* Clean up */
	if (fclose(fp_file) == EOF)
	{
		fprintf(stderr, "Error: Can't close the file %s in stream %p\n",
				cp_filename, (void *)fp_file);
		exit(EXIT_FAILURE);
	}
	if (stack != NULL)
		free_stack(&stack);

	return (0);
}
