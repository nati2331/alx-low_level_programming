#include "lists.h"
#include <stdio.h>
/**
 * print_dlistint: it is a function that prints all elements of a dlistint_t.
 * @h:  head of the linked list
 * Description: size_t is the return value.
 * Return - the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	int i = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
	return (i);
}
