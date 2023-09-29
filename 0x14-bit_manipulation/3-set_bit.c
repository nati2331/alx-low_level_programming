#include "main.h"

/**
 * set_bit - it is a function sets a bit at a given index to 1
 * @index - index of the bit to set to 1
 * @n - it is a pointer to the number to change.
 * Return - 1 for success, -1 if not.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}

