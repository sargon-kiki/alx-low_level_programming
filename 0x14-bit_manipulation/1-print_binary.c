#include "main.h"

/**
 * print_binary - prints binary equivalent of decimal number
 * @n: input argument of type long int
 */
void print_binary(unsigned long int n)
{
	int counter = 0;
	unsigned long int tracker;
	/* unsigned integer range */

	for (int j = 63; j >= 0; j--)

	{
		tracker = n >> j;

		if (tracker & 1)
		{
			_putchar('1');
			counter++;
		}
		else if (counter)
			_putchar('0');
	}
	if (!counter)
		_putchar('0');
}
