#include "lists.h"
#include <stdio.h>

/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: singly linked list to check.
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */
int check_cycle(listint_t *list)
{
	listint_t *ptr;

	if (!list || !(list->next))
		return (0);
	for (ptr = list->next; ptr; ptr = ptr->next)
	{
		if (ptr == list)
			return (1);
	}

	return (0);
}
