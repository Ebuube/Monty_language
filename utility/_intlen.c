#include "../monty.h"

/**
 * _intlen - calculates the number of digits that make up an integer
 * @num: the number
 *
 * Return: the number of digits in the integer
 */
size_t _intlen(int num)
{
	int base = 10;	/* Working in base ten */
	size_t i = 0;

	if (num == 0)
	{
		return (1);
	}

	for (i = 0; num != 0; i++)
		num = (int) num / base;

	return (i);
}
