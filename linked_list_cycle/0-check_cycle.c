#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: singly linked list to check.
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */
int check_cycle(listint_t *list)
{
	listint_t *hare, *tortoise;

	if (!list)
		return (0);
	tortoise = list;
	hare = list;

	while (hare->next && hare->next->next)
	{
		hare = hare->next->next;
		tortoise = tortoise->next;
		if ((unsigned long int)hare == (unsigned long int)tortoise)
			return (1);
	}

	return (0);
}
