#include "main.h"

/**
 * _islower - function
 * @c: the char
 * Return: 1 if lowercase else 0
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z') /*if c is inclusively between a and z */
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
