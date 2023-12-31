#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the hash table
 *
 * Return: pointer to the new table, or NULL on failure
 */
hash_table_t *shash_table_create(unsigned long int size)
{
    hash_table_t *sht;
    unsigned long int i;

    sht = malloc(sizeof(hash_table_t));
    if (sht == NULL)
        return (NULL);
    sht->size = size;
    sht->shead = NULL;
    sht->stail = NULL;
    sht->array = malloc(sizeof(shash_node_t) * size);
    if (sht->array == NULL)
    {
        free(sht);
        return (NULL);
    }
    for (i = 0; i < size; i++)
    {
        sht->array[i] = NULL;
    }
    return (sht);
}

/**
 * shash_table_set - sets a key to a value in the hash table
 * @ht: sorted hash table
 * @key: key to the data
 * @value: data to add
 *
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    char *new_value;
    shash_node_t *shn, *tmp;

    if (ht == NULL || ht->array == NULL || ht->size == 0 ||
        key == NULL || strlen(key) == 0 || value == NULL)
        return (0);
    index = key_index((const unsigned char *)key, ht->size);
    tmp = ht->array[index];
    while (tmp != NULL)
    {
        if (strcmp(tmp->key, key) == 0)
        {
            new_value = strdup(value);
            if (new_value == NULL)
                return (0);
            free(tmp->value);
            tmp->value = new_value;
            return (1);
        }
        tmp = tmp->next;
    }
    shn = make_shash_node(key, value);
    if (shn == NULL)
        return (0);
    shn->next = ht->array[index];
    ht->array[index] = shn;
    add_to_sorted_list(ht, shn);
    return (1);
}

/**
 * shash_table_print - prints a sorted hash table
 * @ht: hash table to print
 *
 * Return: void
 */
void shash_table_print(const hash_table_t *ht)
{
    shash_node_t *tmp;
    char flag = 0; /* 0 before printing any data, 1 after*/

    if (ht == NULL || ht->array == NULL)
        return;
    printf("{");
    tmp = ht->shead;
    while (tmp != NULL)
    {
        if (flag == 1)
            printf(", ");
        printf("'%s': '%s'", tmp->key, tmp->value);
        flag = 1;
        tmp = tmp->snext;
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse
 * @ht: hash table to print
 *
 * Return: void
 */
void shash_table_print_rev(const hash_table_t *ht)
{
    shash_node_t *tmp;
    char flag = 0; /* 0 before printing any data, 1 after*/

    if (ht == NULL || ht->array == NULL)
        return;
    printf("{");
    tmp = ht->stail;
    while (tmp != NULL)
    {
        if (flag == 1)
            printf(", ");
        printf("'%s': '%s'", tmp->key, tmp->value);
        flag = 1;
        tmp = tmp->sprev;
    }
    printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: hash table to delete
 *
 * Return: void
 */
void shash_table_delete(hash_table_t *ht)
{
    unsigned long int i;
    shash_node_t *next;

    if (ht == NULL || ht->array == NULL || ht->size == 0)
        return;
    for (i = 0; i < ht->size; i++)
    {
        while (ht->array[i] != NULL)
        {
            next = ht->array[i]->next;
            free(ht->array[i]->key);
            free(ht->array[i]->value);
            free(ht->array[i]);
            ht->array[i] = next;
        }
    }
    free(ht->array);
    ht->array = NULL;
    ht->shead = ht->stail = NULL;
    ht->size = 0;
    free(ht);
}
