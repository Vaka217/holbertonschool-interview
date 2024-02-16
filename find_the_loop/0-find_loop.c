#include "lists.h"

/**
 * find_listint_loop - checks if a singly linked list has a cycle in it.
 * @head: singly linked list to check.
 * Return: The node where teh cycle starts if there is a cycle, NULL otherwise.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *hare, *tortoise;

	if (!head)
		return (0);
	tortoise = head;
	hare = head;

	while (hare && tortoise && hare->next)
	{
		hare = hare->next->next;
		tortoise = tortoise->next;
		if (hare == tortoise)
			return (tortoise);
	}

	return (NULL);
}
