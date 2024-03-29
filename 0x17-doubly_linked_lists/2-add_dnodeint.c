#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the beginning of a dlistint_t list.
 * @head: A pointer to the head of the dlistint_t list.
 * @n: The integer for the new node to contain.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new node.
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *s_list;

	s_list = malloc(sizeof(dlistint_t));
	if (s_list == NULL)
		return (NULL);

	s_list->n = n;
	s_list->prev = NULL;
	s_list->next = *head;
	if (*head != NULL)
		(*head)->prev = s_list;
	*head = s_list;

	return (s_list);
}
