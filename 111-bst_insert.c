#include "binary_trees.h"

binary_tree_t *new_node(int val)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	node->n = val;
	node->left = node->right = NULL;

	return (node);

}

/**
 * bst_insert - inserts value in Binary Search Tree
 * @tree: double pointer of root node of BST
 * @value: value to insert
 * Return: pointer to created node, otherwise NULL
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	if (*tree == NULL)
		return (binary_tree_node(NULL, value));

	if (value < (*tree)->n)
		(*tree)->left = bst_insert((bst_t **)(*tree)->left, value);
	else if (value > (*tree)->n)
		(*tree)->right = bst_insert((bst_t **)(*tree)->right, value);

	return ((bst_t *)tree);
}
