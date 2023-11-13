#include "main.h"
/**
 * _memset - function.
 * @s: address
 * @b: value
 * @n: no of bytes to be changed.
 * Return: changed array.
 */
char *_memset(char *s, char b, unsigned int n)
{
int i = 0;

for (; n > 0; i++)
{
s[i] = b;
n--;
}
return (s);
}
