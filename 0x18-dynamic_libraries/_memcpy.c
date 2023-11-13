#include "main.h"
/**
 * _memcpy - function
 * @dest: parameter
 * @src: string
 * @n: number
 * Return: pointer 
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int k = 0;

	for (; k < n; k++)
	{
		dest[k] = src[k];
	}

	return (dest);
}
