#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as a right child
 * @parent: parent node of the node to be created
 * @value: value of the node to be created
 * Return: pointer to new node, otherwise NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if ((node == NULL) || (parent == NULL))
	{
		free(node);
		return (NULL);
	}

	node->n = value;
	node->parent = parent;
	node->left = NULL;

	if (parent->right)
	{
		node->right = parent->right;
		parent->right->parent = node;
		parent->right = node;
	}
	else
	{
		parent->right = node;
		node->right = NULL;
	}

	return (node);
	free(node);
}
