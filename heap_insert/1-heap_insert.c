#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/*
 * heaping_time - Iterates back through parent to acommodate the values
 *
 * @node: Pointer to the heaping node
 */
void heaping_time(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		int tmp = node->n;

		node->n = node->parent->n;
		node->parent->n = tmp;

		node = node->parent;
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 *
 * @root: Double pointer to the root node of the Heap
 * @value: Value to put in the new node
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *current;

	if (!root)
		return (NULL);

	new = binary_tree_node(NULL, value);
	if (!new)
		return (NULL);
	if (!*root)
	{
		*root = new;
		return (new);
	}
	current = *root;
	while (current)
	{
		if (!current->left)
		{
			current->left = new;
			new->parent = current;
			break;
		}
		else if (!current->right)
		{
			current->right = new;
			new->parent = current;
			break;
		}
		if (current->left->left && current->left->right && !current->right->right)
			current = current->right;
		else
			current = current->left;
	}
	while (new->parent && (new->n > new->parent->n))
	{
		new->n = new->parent->n;
		new->parent->n = value;
		new = new->parent;
	}
	return (new);
}
