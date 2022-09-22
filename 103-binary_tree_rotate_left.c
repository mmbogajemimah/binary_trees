#include "binary_trees.h"

void binary_tree_delete_node(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	binary_tree_delete(tree->right);
	binary_tree_delete(tree->left);

	free(tree);
}

/**
 * binary_tree_rotate_left - performs left rotation on binary tree
 * @tree: pointer to root node of tree
 * Return: pointer to new root node of tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp, *root = tree;

	temp = tree->right;
	temp->parent = NULL;
	printf("Root node now: %d\n", temp->n);
	printf("checkpoint 1 passed successfully!\n\n");

	free(root->left);
	free(root->right);

	printf("root node: %d\n", root->right->n);

	temp->left = root;
	// temp->left->parent = temp;
	// temp->left->left = NULL;
	// printf("Root node %d left child: %d\n", temp->n, temp->left->n);
	// printf("Root node %d right child: %d\n", temp->n, temp->right->n);
	// printf("checkpoint 2 passed successfully!\n\n");

	// if (temp->left->left->n)
	// 	printf("Left child left child: (nil)\n");
	// else
	// 	printf("Something is going wrong\n");

	// // printf("Left child right child: %d\n", temp->left->right->n);
	// printf("here maybe?\n");
	// if (tree->right->left)
	// {
	// 	temp->left->right = tree->right->left;
	// 	temp->left->right->parent = temp->left->right;
	// }

	// printf("checkpoint 3 passed successfully!\n\n");

	// temp->left->parent = temp;

	// if (tree->right->left)
	// 	temp->left->right = tree->right->left;

	return (temp);
}
