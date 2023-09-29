#include "main.h"

/**
 * clear_bit - it is a funtion that sets the value of a givven bit to 0.
 * @index - index of the bit to clear.
 * @n - it is a pointer to the number to change.
 * Return - 1 for success, -1 for failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}

