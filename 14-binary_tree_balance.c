#include <stdlib.h>
#include "binary_trees.h"

/**
 * height_nodes - Measures the height of a tree counting nodes
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height in nodes (0 for NULL, 1 for a leaf)
 */
static size_t height_nodes(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = height_nodes(tree->left);
	right = height_nodes(tree->right);

	if (left > right)
		return (1 + left);
	return (1 + right);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((int)height_nodes(tree->left) - (int)height_nodes(tree->right));
}
