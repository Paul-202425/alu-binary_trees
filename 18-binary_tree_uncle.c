#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle of
 *
 * Return: Pointer to the uncle, or NULL if node has no parent or
 *         grandparent, or if it has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	parent = node->parent;
	if (parent->parent == NULL)
		return (NULL);

	if (parent->parent->left == parent)
		return (parent->parent->right);
	return (parent->parent->left);
}
