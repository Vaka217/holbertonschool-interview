#include "lists.h"
#include <stdlib.h>

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	const listint_t *current = *head;
	unsigned int i, n = 0;

	if (!*head || !(*head)->next)
		return (1);

	while (current)
	{
		current = current->next;
		n++;
	}

	int *half_list = malloc((n / 2) * sizeof(int));

	for (i = 0; i < (n / 2); i++)
	{
		half_list[i] = (*head)->n;
		*head = (*head)->next;
	}

	if (n % 2 != 0)
		*head = (*head)->next;

	for (i = (n / 2); i > 0; i--)
	{
		if ((*head)->n != half_list[i - 1])
			return (0);
		*head = (*head)->next;
	}
	return (1);
}