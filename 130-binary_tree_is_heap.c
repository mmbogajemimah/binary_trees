#include "binary_trees.h"

/**
 * binary_tree_size - measures size of binary tree
 * @tree: pointer to root node of tree to be measured
 * Return: size of tree, otherwise 0
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size = 0;
	size_t right_size = 0;

	if (tree == NULL)
		return (0);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (left_size + right_size + 1);
}


int is_heap(const binary_tree_t *tree, int a, int b)
{
	if (tree == NULL)
		return (1);

	if (a >= b)
		return (1);

	if ((tree->left && tree->left->n <= tree->n) || (tree->right && tree->right->n <= tree->n))
		return (0);

	return (is_heap(tree->left, 2 * a + 1, b) && is_heap(tree->right, 2 * a + 2, b));
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to root node of tree to check
 * Return: 1 if tree is valid MBH, 0 if it isn't or if it's NULL
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	int i = 0;
	if (tree == NULL)
		return (0);
	return is_heap(tree, i, binary_tree_size(tree));
}
