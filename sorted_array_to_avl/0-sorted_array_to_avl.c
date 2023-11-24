#include "binary_trees.h"

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
 * recursive_sort - Recursive function to build AVL tree
 *
 * @array: Pointer to the first element of the array to be converted
 * @start: Index of the start of the array or subarray to take middle
 * @end: Index of the end of the array or subarray to take middle
 *
 * Return:  A pointer to the root node of the created AVL tree, or
 * NULL on failure
 */
avl_t *recursive_sort(int *array, int start, int end)
{
	int middle;
	avl_t *new;

	if (start > end)
		return (NULL);

	middle = (start + end) / 2;

	new = binary_tree_node(NULL, array[middle]);

	if (!new)
		return (NULL);

	new->left = recursive_sort(array, start, middle - 1);
	if (new->left)
		new->left->parent = new;

	new->right = recursive_sort(array, middle + 1, end);
	if (new->right)
		new->right->parent = new;

	return (new);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 *
 * @array: Pointer to the first element of the array to be converted
 * @size: The number of elements in the array
 *
 * Return:  A pointer to the root node of the created AVL tree, or
 * NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (recursive_sort(array, 0, size - 1));
}
