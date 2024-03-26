#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: The size of the tree
 * If tree is NULL, return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

    /* Measure the size of the left subtree */
	size_t left_size = binary_tree_size(tree->left);

    /* Measure the size of the right subtree */
	size_t right_size = binary_tree_size(tree->right);


	return (left_size + right_size + 1);
}
