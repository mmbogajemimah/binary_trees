#include "binary_trees.h"
#include <limits.h>

/**
 * is_valid_bst - helper function to check if binary tree is valid BST
 * @tree: pointer to root node of tree to check
 * @min_range: minimum value to check against
 * @max_range: maximum value to check against
 * Return: biggest value in the tree
 */
int is_valid_bst(const binary_tree_t *tree, int min_range, int max_range)
{
	int left_bst = 0;
	int right_bst = 0;

	if (tree == NULL)
		return (1);

	if ((tree->n < min_range) || (tree->n > max_range))
		return (0);

	left_bst = is_valid_bst(tree->left, min_range, tree->n - 1);
	right_bst = is_valid_bst(tree->right, tree->n + 1, max_range);

	if (left_bst && right_bst)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_is_bst - checks if binary tree is valid Binary Search Tree
 * @tree: pointer to root node of tree
 * Return: 1 if tree is valid BST, 0 if it's not or if it's NULL
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_valid_bst(tree, INT_MIN, INT_MAX));
}
