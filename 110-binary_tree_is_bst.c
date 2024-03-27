#include "binary_trees.h"

/**
 * check_sub_tree_Left - check if all nodes are smaller than
 * the root specified
 * @node: node in the tree to verify condition
 * @max: value to compare
 * Return: 1 if all nodes are smaller or equal or 0 if not
 */
int check_sub_tree_Left(const binary_tree_t *node, int max)
{
	int isLeftSubtreeValid = 0, isRightSubtreeValid = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n >= max)
			return (0);
		isLeftSubtreeValid = check_sub_tree_Left(node->left, max);
		isRightSubtreeValid = check_sub_tree_Left(node->right, max);
		if (isLeftSubtreeValid == isRightSubtreeValid && isLeftSubtreeValid == 1)
			return (1);
		return (0);
	}
}

/**
 * check_sub_tree_Right - check if all the nodes are bigger than the
 * root specified
 * @node: node in the tree to verify condition
 * @min: value to compare
 * Return: 1 if all is bigger or equal or 0 if not
 */
int check_sub_tree_Right(const binary_tree_t *node, int min)
{
	int isLeftSubtreeValid = 0, isRightSubtreeValid = 0;

	if (node == NULL)
	{
		return (1);
    	}
	else
	{
		if (node->n <= min)
			return (0);
		isLeftSubtreeValid = check_sub_tree_Right(node->left, min);
		isRightSubtreeValid = check_sub_tree_Right(node->right, min);
		if (isLeftSubtreeValid == isRightSubtreeValid && isLeftSubtreeValid == 1)
			return (1);
		return (0);
	}
}

/**
 * binary_tree_is_bst - says if a tree is a bst or not
 * the process here is first verify that the left node be smaller than the root
 * then verify if the right node is bigger than th root.
 * after that verify if the left subtree has nodes smaller than root
 * and the right subtree has bigger nodes than root
 * @tree: node that point to the tree to check
 * Return: 1 if it is a BST or 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int isLeftSubtreeBST = 0, isRightSubtreeBST = 0;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
    	if (tree->right && tree->right->n < tree->n)
        	return (0);
    	if (tree->left && tree->left->n < tree->n)
	{
		isLeftSubtreeBST = check_sub_tree_Left(tree->left, tree->n);
		if (isLeftSubtreeBST == 0)
            		return (0);
		isLeftSubtreeBST = binary_tree_is_bst(tree->left);
	}
	if (tree->right && tree->right->n > tree->n)
    	{
        	isRightSubtreeBST = check_sub_tree_Right(tree->right, tree->n);
		if (isRightSubtreeBST == 0)
            		return (0);
		isRightSubtreeBST = binary_tree_is_bst(tree->right);
    	}
	if (isLeftSubtreeBST != 2 || isRightSubtreeBST != 2)
	{
		if (isLeftSubtreeBST == 0 || isRightSubtreeBST == 0)
            		return (0);
	}
	return (1);
}
