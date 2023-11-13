#include "main.h"
/**
 * *_strchr - function.
 * @s: string
 * @c: Character
 * Return: Pointer
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			break;
		}
	}

	if (s[i] == c)
	{
		return (i + s);
	}

	return (0);
}
