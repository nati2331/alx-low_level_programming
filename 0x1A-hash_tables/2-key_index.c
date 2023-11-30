#include "hash_tables.h"

/*
 * key_index: function gives index of key
 * @key: key string.
 * @size: size of arr
 * Return: the index
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
