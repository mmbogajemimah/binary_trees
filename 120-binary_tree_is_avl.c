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
 * binary_tree_is_avl - checks if binary tree is valid AVL tree
 * @tree: pointer to root node of tree
 * Return: 1 if tree is valid AVL, 0 if it's not or it's null
 */

int is_avl(const binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;
	int height_diff = 0;
	int left_avl = 0;
	int right_avl = 0;

	if (tree == NULL)
		return (1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	
	if (left_height > right_height)
		height_diff = left_height - right_height;
	else
		height_diff = right_height - left_height;

	left_avl = is_avl(tree->left);
	right_avl = is_avl(tree->right);

	if ((height_diff <= 1) && (left_avl != 0) && (right_avl != 0))
		return (1);
	return (0);
}

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);
	return (is_avl(tree));
}

