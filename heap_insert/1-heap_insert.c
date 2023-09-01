#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_height - Calculates the height of a binary tree
 * Return: Height
 * @tree: Root of the tree
 */

size_t binary_tree_height(const binary_tree_t *tree, int left)
{
	size_t h = 0;

	if (!tree)
		return (0);
	if (left == 1)
		h = tree->left ? 1 + binary_tree_height(tree->left, 1) : 0;
	else
		h = tree->right ? 1 + binary_tree_height(tree->right, 0) : 0;
	return (h);
}

/**
 * binary_tree_perfect - Checks if a binary tree is perfect
 *
 * @tree: Root of the tree
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_perfect(const binary_tree_t *tree)
{
	int left_check, right_check, left_part, right_part;

	if (tree && binary_tree_height(tree, 1) == binary_tree_height(tree, 0))
	{
		if (!binary_tree_height(tree, 1))
			return (1);

		left_check = !((tree->left)->left) && !((tree->left)->right);
		right_check = !((tree->right)->left) && !((tree->right)->right);

		if ((tree->left && left_check) && (tree->right && right_check))
			return (1);

		if (tree && tree->left && tree->right)
		{
			left_part = binary_tree_perfect(tree->left);
			right_part = binary_tree_perfect(tree->right);
			return (left_part && right_part);
		}
	}

	return (0);
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

	parent = *root;
	while (parent->left && parent->right)
	{
		if (binary_tree_perfect(parent) || !binary_tree_perfect(parent->left))
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
