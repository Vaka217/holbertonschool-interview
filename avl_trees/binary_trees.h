#ifndef BINARY_TREES
#define BINARY_TREES
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define MY_INT_MIN INT_MIN

#define MY_INT_MAX INT_MAX

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;
void binary_tree_print(const binary_tree_t *);
int binary_tree_is_avl(const binary_tree_t *tree);
int is_bst_helper(const binary_tree_t *tree, int min, int max);
int calculate_height(binary_tree_t *tree);
#endif
