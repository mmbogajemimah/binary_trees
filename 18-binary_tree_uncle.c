#include "binary_trees.h"

/**
 * binary_tree_uncle - finds uncle of a node
 * @node: node to check
 * Return: pointer to uncle node, otherwise NULL
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);

	if ((node->parent == NULL) || (node->parent->parent == NULL))
		return (NULL);
	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right);

	return (node->parent->parent->left);
}
