#include <stdio.h>
#include <stdlib.h>
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
        return NULL;

    new->n = value;
    new->left = NULL;
    new->right = NULL;

    if (!parent)
    {
        new->parent = NULL;
        return new;
    }

    new->parent = parent;

    if (!parent->left)
        parent->left = new;
    else if (!parent->right)
        parent->right = new;
    else
        return NULL;

    return new;
}
