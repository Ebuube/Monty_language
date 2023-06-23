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
	UNUSED FILE *fp_in_file = NULL;		/* file pointer to stream */
	UNUSED char *cp_filename = NULL;	/* pointer to filename */

	if (argc < 2)		/* Open file */
	{/* Ensure file exists */
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	cp_filename = argv[1];	/* set name of bytecode file */

	fp_in_file = fopen(cp_filename, "r");
	if (fp_in_file == NULL)
	{/* File doesn't exist */
		fprintf(stderr, "Error: Can't open file %s\n", cp_filename);
		exit(EXIT_FAILURE);
	}

	/* Execute instructions in the stream */
	if (read_file(fp_in_file) != 0)
	{
		fprintf(stderr, "ERROR: failure on reading file \'%s\'\n",
				cp_filename);
		exit(EXIT_FAILURE);
	}

	/* clean up */
	fclose(fp_in_file);

	return (0);
}
