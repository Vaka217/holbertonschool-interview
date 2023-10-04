#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: singly linked list to check.
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */
int check_cycle(listint_t *list)
{
	unsigned long int *addresses;
	int i, addresses_len = 0;

	if (!list)
		return (0);
	addresses = malloc(sizeof(unsigned long int));
	if (!addresses)
		exit(EXIT_FAILURE);
	addresses[addresses_len] = (unsigned long int)list;
	addresses_len++;
	while (list->next)
	{
		for (i = 0; i < addresses_len; i++)
		{
			if (addresses[i] == (unsigned long int)(list->next))
			{
				free(addresses);
				return (1);
			}
		}
		addresses_len++;
		addresses = realloc(addresses, sizeof(unsigned long int) * addresses_len);
		if (!addresses)
			exit(EXIT_FAILURE);
		list = list->next;
		addresses[addresses_len - 1] = (unsigned long int)list;
	}

	free(addresses);
	return (0);
}
