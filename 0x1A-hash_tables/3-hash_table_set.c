#include "hash_tables.h"

/**
 * hash_table_set - update an element in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Else - 1.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *NP;
	char *vc;
	unsigned long int index, k;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	vc = strdup(value);
	if (vc == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	for (k = index; ht->array[k]; k++)
	{
		if (strcmp(ht->array[k]->key, key) == 0)
		{
			free(ht->array[k]->value);
			ht->array[k]->value = vc;
			return (1);
		}
	}

	NP = malloc(sizeof(hash_node_t));
	if (NP == NULL)
	{
		free(vc);
		return (0);
	}
	NP->key = strdup(key);
	if (NP->key == NULL)
	{
		free(NP);
		return (0);
	}
	NP->value = vc;
	NP->next = ht->array[index];
	ht->array[index] = NP;

	return (1);
}
