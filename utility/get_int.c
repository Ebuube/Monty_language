#include "../monty.h"

/**
 * get_int - wrapper on strtol() to get int from string
 * @str: the string to convert
 *
 * Return: the integer received, INT_MIN if underflow, INT_MAX if overflow
 */
int get_int(char *str)
{
	long num = 0;	/* return value */
	char *endptr = NULL;	/* First non-digit character */
	int base = 10;		/* For decimal conversion */

	errno = 0;	/* Expecting a possible change in errno */
	num = strtol(str, &endptr, base);
	if (num == LONG_MAX || num >= INT_MAX)
	{/* overflow */
		return (INT_MAX);
	}
	if (num == LONG_MIN || num <= INT_MIN)
	{/* underflow */
		return (INT_MIN);
	}

	return (num);
}
