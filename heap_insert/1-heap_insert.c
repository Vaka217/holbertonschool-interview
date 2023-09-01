#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * Return: The number of leaves, 0 otherwise
 * @tree: pointer to the root node of the tree to count the number of leaves
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		leaves++;
	if (tree->left)
		leaves += binary_tree_leaves(tree->left);
	if (tree->right)
		leaves += binary_tree_leaves(tree->right);
	return (leaves);
}

/**
 * heaping_time - Restores the Max Heap property by moving a node value up
 * @new: A pointer to the node to be move
 * @value: Value to be passed
 */
void heaping_time(heap_t *new, int value)
{
	while (new->parent && (new->n > new->parent->n))
	{
		new->n = new->parent->n;
		new->parent->n = value;
		new = new->parent;
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to put in the new node
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *parent;
	size_t leaves = 0;

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

	leaves = binary_tree_leaves(*root);
	parent = *root;
	while (parent->left && parent->right)
	{
		if (leaves > 0 && leaves % 2 == 0)
			parent = parent->left;
		else
			parent = parent->right;
	}

	if (!parent->left)
		parent->left = new;
	else
		parent->right = new;

	new->parent = parent;
	heaping_time(new, value);
	return (new);
}
