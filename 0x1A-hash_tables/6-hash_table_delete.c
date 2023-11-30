#include "hash_tables.h"

/**
 * hash_table_delete - function deletes hash table.
 * @ht: pointer
 * Return: the deleted table
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *tem, *next;
	unsigned long int index;

	if (!ht)
		return;
	for (index = 0; index < ht->size; index++)
		for (tem = ht->array[index]; tem; tem = next)
		{
			next = tem->next;
			free(tem->key);
			free(tem->value);
			free(tem);
		}
	free(ht->array);
	free(ht);
}
