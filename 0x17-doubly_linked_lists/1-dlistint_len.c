#include "lists.h"


/**
 * dlistint_len - Count the number of elements
 * @h: The head of the linked list
 * Return: The number of elements in the list
*/

size_t dlistint_len(const dlistint_t *h)
{
size_t c_nodes = 0;
while (h)
{
c_nodes++;
h = h->next;
}

return (c_nodes);

}
