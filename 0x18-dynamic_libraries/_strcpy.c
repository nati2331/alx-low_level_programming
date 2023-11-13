#include "main.h"
/**
 * *_strcpy - function
 * @dest: destination
 * @src: string origin,
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int len;
	int i;

	for (len = 0; src[len] != '\0'; len++)
	{
	}

	for (i = 0; i <= len; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
