#include "binary_trees.h"

/**
 * binary_tree_nodes - counts nodes with at least 1 child
 * @tree: pointer to root node of tree to be checked
 * Return: number of nodes, otherwise 0
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_nodes = 0;
	size_t right_nodes = 0;

	if (tree == NULL)
		return (0);

	left_nodes = binary_tree_nodes(tree->left);
	right_nodes = binary_tree_nodes(tree->right);

	return (left_nodes + right_nodes + 1);
}

/**
 * is_complete - helper function to check if binary tree is complete
 * @tree: pointer to root node of tree
 * @index: index
 * @number_nodes: number of nodes
 * Return: 1 if tree is complete, otherwise 0
 */
int is_complete(const binary_tree_t *tree, int index, int number_nodes)
{
	int left_complete = 0;
	int right_complete = 0;

	if (tree == NULL)
		return (1);

	if (index >= number_nodes)
		return (0);

	left_complete = is_complete(tree->left, index * 2, number_nodes);
	right_complete = is_complete(tree->right, index * 2 + 1, number_nodes);
	return (left_complete && right_complete);
}

/**
 * binary_tree_is_complete - checks if binary tree is complete
 * @tree: root node of tree to check
 * Return: 1 if true, otherwise 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int nodes;

	if (tree == NULL)
		return (0);

	nodes = binary_tree_nodes(tree);

	return (is_complete(tree, 1, nodes + 1));
}
