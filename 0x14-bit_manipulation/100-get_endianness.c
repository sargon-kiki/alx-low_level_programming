#include "main.h"

/**
 * get_endianness - verify if machine is big or small endian
 * Return: 1 for little, 0 for small
 */
int get_endianness(void)
{
	unsigned int j = 1;
	char *c = (char *) &j;

	return (*c);
}
