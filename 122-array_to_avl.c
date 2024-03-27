#include "binary_trees.h"

/**
 * array_to_avl - turns an array to a avl tree
 * @array: array to turns to AVL tree
 * @size: size of array
 * Return: AVL tree from array
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t curr_index, dup_index = 0;
	avl_t *rootNode;

	rootNode = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (curr_index = 0; curr_index < size; curr_index++)
	{
		for (dup_index = 0; dup_index < curr_index; dup_index++)
		{
			if (array[dup_index] == array[curr_index])
				break;
		}
		if (dup_index == curr_index)
		{
			if (avl_insert(&rootNode, array[curr_index]) == NULL)
			{
				return (NULL);
			}
		}
	}
	return (rootNode);
}
