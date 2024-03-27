#include "binary_trees.h"

/**
 * binary_tree_height - Function that measures the height of a binary tree
 * @tree: tree to go through
 * Return: the height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lyt = 0;
	size_t ryt = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->left == NULL && tree->right == NULL)
			return (tree->parent != NULL);
		if (tree)
		{
			lyt = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			ryt = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((lyt > ryt) ? lyt : ryt);
		}
}

/**
 * binary_tree_balance - Measures balance factor of a binary tree
 * @tree: tree to go through
 * Return: balanced factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0, total = 0;

	if (tree)
	{
		left = ((int)binary_tree_height(tree->left));
		right = ((int)binary_tree_height(tree->right));
		total = left - right;
	}
	return (total);
}

/**
 * tree_is_perfect - function that says if a tree is perfect or not
 * it has to be the same quantity of levels in left as right, and also
 * each node has to have 2 nodes or none
 * @tree: tree to check
 * Return: 0 if is not a perfect or other number that is the level of height
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int lyt = 0, ryt = 0;

	if (tree->left && tree->right)
	{
		lyt = 1 + tree_is_perfect(tree->left);
		ryt = 1 + tree_is_perfect(tree->right);
		if (ryt == lyt && ryt != 0 && lyt != 0)
			return (ryt);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * binary_tree_is_perfect - perfect or not a tree
 * @tree: tree to check
 * Return: 1 is it is or 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int findings = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		findings = tree_is_perfect(tree);
		if (findings != 0)
		{
			return (1);
		}
		return (0);
	}
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: tree to check
 * Return: 1 is it is or 0 if not
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int balanceValue;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left && tree->left->n > tree->n)
	{
		return (0);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		return (0);
	}
	if (binary_tree_is_perfect(tree))
	{
		return (1);
	}
	balanceValue = binary_tree_balance(tree);
	if (balanceValue == 0)
	{
		return (binary_tree_is_perfect(tree->left)
			&& binary_tree_is_heap(tree->right));
	}
	if (balanceValue == 1)
	{
		return (binary_tree_is_heap(tree->left)
			&& binary_tree_is_perfect(tree->right));
	}
	else
	{
		return (0);
	}
}
