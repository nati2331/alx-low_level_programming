#include "hash_tables.h"

/**
 * hash_tabel_set: function updates hash tabel.
 * @ht: is the hash table.
 * @key: is the Key of index.
 * @value: is value of element.
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	char *temporal_value = NULL;
	hash_node_t *tem = NULL, *new = NULL;

	if (!ht || !ht->array || !value)
		return (0);

	if (strlen(key) == 0 || !key)
		return (0);
	temporal_value = strdup(value);
	if (!temporal_value)
		return (0);
	index = key_index((unsigned char *)key, ht->size);


	tem = ht->array[index];
	while (tem)
	{
		if (strcmp(tem->key, key) == 0)
		{
			free(tem->value);
			tem->value = temporal_value;
			tem->value = strdup(value);
			free(temporal_value);
			return (1);
		}
		tem = tem->next;
	}

	new = malloc(sizeof(hash_node_t));
	if (!new)
	{
		free(new);
		return (0);
	}
	new->key = strdup(key);
	new->value = temporal_value;
	new->next = ht->array[index];
	ht->array[index] = new;
	return (1);
}
