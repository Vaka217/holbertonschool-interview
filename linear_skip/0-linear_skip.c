#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: a pointer to the head of the skip list to search in
 * @value: the value to search for
 *
 * Return: a pointer on the first node where value is located, if value is
 * not present in list or if head is NULL, returns NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *count;
	size_t i = 0;

	if (!list)
		return (NULL);

	for (node = list; node; node = node->express)
	{
		if (node->index != 0)
			printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

		if (!node->express)
		{
			for (count = node; count->next; count = count->next)
				i++;
			break;
		}

		i = node->express->index;
		if (node->express && value <= node->express->n)
		{
			printf("Value checked at index [%ld] = [%d]\n",
				   node->express->index, node->express->n);
			break;
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n", node->index, i);

	for (node = node; node; node = node->next)
	{
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
		if (node->n == value)
			return (node);
	}

	return (NULL);
}
