#include "binary_trees.h"

/**
 * calculate_height - calculates the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: height of the tree
 **/
int calculate_height(binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = calculate_height(tree->left);
	right_height = calculate_height(tree->right);

	return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 * is_bst_helper - helper function to check if a binary tree
 * is a binary search tree
 * @tree: pointer to the root node of the tree
 * @min: minimum value allowed in the tree
 * @max: maximum value allowed in the tree
 * Return: 1 if the tree is a BST, otherwise 0
 **/
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst_helper(tree->left, min, tree->n - 1) &&
		  is_bst_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - checks if a binary tree is an AVL tree and a binary
 * search tree
 * @tree: pointer to the root node of the tree
 * Return: 1 if the tree is an AVL tree, otherwise 0
 **/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height, balance;

	if (!tree)
		return (0);

	if (!is_bst_helper(tree, INT_MIN, INT_MAX))
		return (0);

	left_height = calculate_height(tree->left);
	right_height = calculate_height(tree->right);
	balance = left_height - right_height;

	return (balance >= -1 && balance <= 1);
}
