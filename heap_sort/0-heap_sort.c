#include <stdlib.h>
#include "sort.h"

/**
 * binary_tree_node - Creates a binary tree node
 *
 * @parent: Pointer to the parent node of the node to create
 * @value: Value to put in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->left = NULL;
	new->right = NULL;

	if (!parent)
	{
		new->parent = NULL;
		return (new);
	}

	new->parent = parent;

	if (!parent->left)
		parent->left = new;
	else if (!parent->right)
		parent->right = new;
	else
		return (NULL);

	return (new);
}

/**
 * binary_tree_height - Calculates the height of a binary tree
 * @tree: Root of the tree
 * @left: Which branch to go
 * Return: Height
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
 * Return: The moved node
 */
heap_t *heaping_time(heap_t *new, int value)
{
	printf("%d\n", new->n);
	while (new->parent && (new->n > new->parent->n))
	{
		new->n = new->parent->n;
		new->parent->n = value;
		new = new->parent;
		printf("%d\n", new->n);
	}
	return (new);
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
	return (new);
}

void heap_sort(int *array, size_t size)
{
	int i = 0;
	heap_t *root;
	heap_t *node;

	root = NULL;

	for (i = 0; i < size; i++)
		node = heap_insert(&root, array[i]);

	while ()
}