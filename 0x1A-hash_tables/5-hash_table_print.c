#include "hash_tables.h"

/**
 * hash_table_print - Prints out a hash table.
 * @ht: A pointer to the hash table to print.
 *
 * Description: Key/value pairs are printed in the order
 *              they appear in the array of the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *N;
	unsigned long int k;
	unsigned char comma_flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (k = 0; k < ht->size; k++)
	{
		if (ht->array[k] != NULL)
		{
			if (comma_flag == 1)
				printf(", ");

			N = ht->array[k];
			while (N != NULL)
			{
				printf("'%s': '%s'", N->key, N->value);
				N = N->next;
				if (N != NULL)
					printf(", ");
			}
			comma_flag = 1;
		}
	}
	printf("}\n");
}
