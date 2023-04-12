#include "main.h"
/**
 * flip_bits - function that returns the number of bits you would need to flip
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
int counter = 0;
unsigned long int operator = n ^ m;
unsigned long int tracker;


for (int j = 63; j >= 0; j--)
{
	tracker = operator >> j;
	if (tracker & 1)
		counter++;
}

	return (counter);
}
