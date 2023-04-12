#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{

	unsigned int number = 0;

	if (!b)
		return (0);

	for (int j = 0; b[j]; j++)
	{
		if (b[j] < '0' || b[j] > '1')
			return (0);
		number = 2 * number + (b[j] - '0');
	}

	return (number);
}
