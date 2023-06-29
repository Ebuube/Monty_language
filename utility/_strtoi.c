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

	return (num);
}
