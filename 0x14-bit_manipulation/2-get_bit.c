#include "main.h"

/**
 * get_bit - to  returns the value of a bit at a given index.
 * @n: number for search
 * @index: index of the bit
 *
 * Return: the value of the bit at index index or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int converted;

	if (index > 63)
		return (-1);

	converted = (n >> index) & 1;

	return (converted);
}
