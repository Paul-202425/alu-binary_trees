#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

#define LINE_WIDTH 255

/**
 * levels - Counts the number of levels in a binary tree
 * @tree: Pointer to the root of the tree
 *
 * Return: Number of levels (0 for an empty tree)
 */
static size_t levels(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree == NULL)
		return (0);
	l = levels(tree->left);
	r = levels(tree->right);
	return (1 + (l > r ? l : r));
}

/**
 * draw - Draws a node and its subtrees into the line buffers
 * @tree: Pointer to the node to draw
 * @offset: Column where the node's subtree starts
 * @depth: Depth of the node (root is 0), also the line it is drawn on
 * @s: Array of line buffers
 * @center: Set to the column of the middle of this node's text
 *
 * Return: Width in columns used by the subtree
 */
static int draw(const binary_tree_t *tree, int offset, int depth, char **s,
		int *center)
{
	char b[8];
	int width, lw, rw, lc = 0, rc = 0, i;

	if (tree == NULL)
		return (0);
	width = snprintf(b, sizeof(b), "(%03d)", tree->n);
	lw = draw(tree->left, offset, depth + 1, s, &lc);
	rw = draw(tree->right, offset + lw + width, depth + 1, s, &rc);
	for (i = 0; i < width; i++)
		s[depth][offset + lw + i] = b[i];
	if (tree->left)
	{
		for (i = lc + 1; i < offset + lw; i++)
			s[depth][i] = '-';
		s[depth][lc] = '.';
	}
	if (tree->right)
	{
		for (i = offset + lw + width; i < rc; i++)
			s[depth][i] = '-';
		s[depth][rc] = '.';
	}
	*center = offset + lw + width / 2;
	return (lw + width + rw);
}

/**
 * binary_tree_print - Prints a binary tree
 * @binary_tree: Pointer to the root of the tree to print
 */
void binary_tree_print(const binary_tree_t *binary_tree)
{
	char **s;
	size_t h, i, j;
	int center;

	if (binary_tree == NULL)
		return;
	h = levels(binary_tree);
	s = malloc(sizeof(*s) * h);
	if (s == NULL)
		return;
	for (i = 0; i < h; i++)
	{
		s[i] = malloc(LINE_WIDTH);
		if (s[i] == NULL)
		{
			while (i > 0)
				free(s[--i]);
			free(s);
			return;
		}
		memset(s[i], ' ', LINE_WIDTH - 1);
		s[i][LINE_WIDTH - 1] = '\0';
	}
	draw(binary_tree, 0, 0, s, &center);
	for (i = 0; i < h; i++)
	{
		for (j = LINE_WIDTH - 1; j > 0 && s[i][j - 1] == ' '; j--)
			;
		s[i][j] = '\0';
		printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
}
