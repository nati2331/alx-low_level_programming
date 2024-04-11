#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * struct listint_s - singly linked list
 * @n: Int
 * @index: index of node
 * @next: pointer
 */

typedef struct listint_s
{
	int n;
	size_t index;
	struct listint_s *next;
} listint_t;

/**
 * struct skiplist_s - skip list data structure
 * @n: Int
 * @express: array of pointers
 * @next: pointer
 */

typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);
listint_t *jump_list(listint_t *list, size_t size, int value);
skiplist_t *linear_skip(skiplist_t *list, int value);

#endif
