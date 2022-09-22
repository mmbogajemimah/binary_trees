#include "binary_trees.h"

/**
 * binary_tree_node - creates node for a binary tree without any children
 * @parent: pointer to the parent node
 * @value: value to input in the node
 * Return: pointer to new node or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
	{
		free(node);
		return (NULL);
	}

	node->left = NULL;
	node->right = NULL;
	node->parent = parent;
	node->n = value;

	return (node);
	free(node);
}
