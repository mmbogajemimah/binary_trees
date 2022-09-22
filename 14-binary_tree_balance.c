#include "binary_trees.h"

/**
 * binary_tree_height - measure height of binary tree
 * @tree: pointer to root node of tree
 * Return: 0 if tree is NULL, otherwise return the height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}


/**
 * binary_tree_balance - measures balance factor of binary tree
 * @tree: pointer to root node of tree to be measured
 * Return: balance factor of tree, otherwise 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if ((tree == NULL) || ((tree->left == NULL) && (tree->right == NULL)))
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
