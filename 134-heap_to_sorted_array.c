#include "binary_trees.h"

/**
 * tree_size - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + tree_size(tree->left);

	if (tree->right)
		right_height = 1 + tree_size(tree->right);

	return (left_height + right_height);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 *
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 *
 * Return: pointer to array sorted in descending order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int index, *array = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	array = malloc(sizeof(int) * (*size));

	if (!array)
		return (NULL);

	for (index = 0; heap; index++)
		array[index] = heap_extract(&heap);

	return (array);
}
