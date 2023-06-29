#include "../monty.h"


/**
 * _strtoi - converts a string to a valid number
 * @str: the string
 *
 * Return: the number derived from the string,
 * INT_MIN if number is invalid our is an underflow/overflow to int
 */

int _strtoi(UNUSED char *str)
{
	int num = 0;
	size_t num_len = 0;

	if (str == NULL)
	{
		return (INT_MIN);
	}

	num = atoi(str);

	if ((num == 0) &&
		((str[0] != '0' ||
		  str[0] != '+' ||
		  str[0] != '-') &&
		 (str[1] == '\n')))
	{
		return (INT_MIN);
	}

	/* Ensure that the whole string is a valid integer */
	num_len = _intlen(num);

	num_len = (str[0] == '+' || str[0] == '-') ? num_len + 1 : num_len;

	if (num_len != strlen(str))
	{
		return (INT_MIN);
	}

	return (num);
}
