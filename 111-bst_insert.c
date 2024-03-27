#include "binary_trees.h"
/**
 * bst_insert - insert nodes in order to create a BST tree
 * @tree: tree to create with type BST
 * @value: value of node to insert
 * Return: BST tree
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *t;
	binary_tree_t *aux;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		aux = binary_tree_node((binary_tree_t *)(*tree), value);
		new = (bst_t *)aux;
		*tree = new;
	}
	else
	{
		t = *tree;
		if (value < t->n)
		{
			if (t->left)
				new = bst_insert(&t->left, value);
			else
			{
				aux = binary_tree_node((binary_tree_t *)t, value);
				new = t->left = (bst_t *)aux;
			}
		}
		else if (value > t->n)
		{
			if (t->right)
				new = bst_insert(&t->right, value);
			else
			{
				aux = binary_tree_node((binary_tree_t *)t, value);
				new = t->right = aux;
			}
		}
		else
			return (NULL);
	}
	return (new);
}
