#include "binary_trees.h"
/**
 * array_to_bst - turns an array to a BST tree
 * @array: array to turns to BST tree
 * @size: size of array
 * Return: BST tree from array
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t index = 0;
	bst_t *rootNode;

	rootNode = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (; index < size; index++)
	{
		if (index == 0)
		{
			bst_insert(&rootNode, array[index]);
		}
		else
		{
			bst_insert(&rootNode, array[index]);
		}
	}
	return (rootNode);
}
