#include "main.h"
/**
 * _strncat - function
 * @dest: destination
 * @src: origin
 * @n: number of char
 * Return: pointer to the dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	for (; dest[i] != '\0'; i++)
	{
	} /* get the length of the destination */

	for (; src[j] != '\0'; j++)
	{
		if (n > j)
		{
			dest[i] = src[j];
			i++;
		}
	}
	if (n > 0)
	{
		dest[i] = '\0';
	}

	return (dest);
}
