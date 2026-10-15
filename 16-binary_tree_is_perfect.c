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
 * count_nodes - Counts all the nodes in a tree
 * @tree: Pointer to the root node of the tree to count
 *
 * Return: Number of nodes in the tree
 */
static size_t count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, nodes;

	if (tree == NULL)
		return (0);

	height = height_nodes(tree);
	nodes = count_nodes(tree);

	if (nodes == (((size_t)1 << height) - 1))
		return (1);
	return (0);
}
