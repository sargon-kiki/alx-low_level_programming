#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to a hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head = ht;
	hash_node_t *N, *tmp;
	unsigned long int i;

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			N = ht->array[i];
			while (N != NULL)
			{
				tmp = N->next;
				free(N->key);
				free(N->value);
				free(N);
				N = tmp;
			}
		}
	}
	free(head->array);
	free(head);
}
