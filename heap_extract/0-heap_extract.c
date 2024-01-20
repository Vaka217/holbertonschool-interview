#include "binary_trees.h"

/**
 * binary_tree_height - Check the height of a binary tree
 *
 * @node: Pointer to the node to measure the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t binary_tree_height(const binary_tree_t *node)
{
	size_t left_height;
	size_t right_height;

	left_height = node->left ? 1 + binary_tree_height(node->left) : 0;
	right_height = node->right ? 1 + binary_tree_height(node->right) : 0;
	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_preorder - goes through a binary tree using pre-order traversal
 * @root: pointer to the root of the tree
 * @selected_node: pointer to the selected node in the tree
 * @height: height of the tree
 * @layer: layer on the tree
 **/
void binary_tree_preorder(heap_t *root, heap_t **selected_node, size_t height, size_t layer)
{
	if (!root)
		return;
	if (height == layer)
		*selected_node = root;
	layer++;
	if (root->left)
		binary_tree_preorder(root->left, selected_node, height, layer);
	if (root->right)
		binary_tree_preorder(root->right, selected_node, height, layer);
}

/**
 * heap_sorting - binary tree Heapsort
 * @current_node: pointer to the heap root
 * Return: pointer to the last node
 **/

heap_t *heap_sorting(heap_t *current_node)
{
	int temp;

	while (current_node->left || current_node->right)
	{
		if (!current_node->right || current_node->left->n > current_node->right->n)
		{
			temp = current_node->n;
			current_node->n = current_node->left->n;
			current_node->left->n = temp;
			current_node = current_node->left;
		}
		else if (!current_node->left || current_node->left->n < current_node->right->n)
		{
			temp = current_node->n;
			current_node->n = current_node->right->n;
			current_node->right->n = temp;
			current_node = current_node->right;
		}
	}
	return (current_node);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of the extracted node
 **/

int heap_extract(heap_t **root)
{
	int value;
	heap_t *current_node, *selected_node;

	if (!root || !*root)
		return (0);
	current_node = *root;
	value = current_node->n;
	if (!current_node->left && !current_node->right)
	{
		*root = NULL;
		free(current_node);
		return (value);
	}
	binary_tree_preorder(current_node, &selected_node, binary_tree_height(current_node), 0);
	current_node = heap_sorting(current_node);
	current_node->n = selected_node->n;
	if (selected_node->parent->right)
		selected_node->parent->right = NULL;
	else
		selected_node->parent->left = NULL;
	free(selected_node);
	return (value);
}
