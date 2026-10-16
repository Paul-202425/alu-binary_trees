#include <stdlib.h>
#include "binary_trees.h"

/**
 * check_full - Checks that every node has either 0 or 2 children
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full (an empty subtree counts as full), else 0
 */
static int check_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (check_full(tree->left) && check_full(tree->right));
}

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, otherwise 0 (also 0 if tree is NULL)
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (check_full(tree));
}
