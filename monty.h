#ifndef __MONTY_H__
#define __MONTY_H__

/* Header files */
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#include <stdio.h>
#endif	/* _GNU_SOURCE */
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>


/* Declaration or Definition of Macros */
#define UNUSED __attribute__((unused))


/* Function prototypes */
int read_file(FILE *stream);
size_t parse_line(char **arr_buffer, size_t buf_size, char *cp_line);
int execute(char *arr_opcode_arg[], size_t line_number);

#endif	/* __MONTY_H__ */
