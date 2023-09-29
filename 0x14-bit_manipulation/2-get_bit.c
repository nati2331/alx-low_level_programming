#include "main.h"

/**
 * get_bit - returns the value of a bit at an index in a decimal number
 * @index - index of the bit
 * @n - it is the number to search
 * Return - it returns the  value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}
