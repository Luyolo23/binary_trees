#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 *
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to the root node of the created Binary Heap,
 * or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t index;
	heap_t *rootNode = NULL;

	if (!array)
		return (NULL);

	rootNode = heap_insert(&rootNode, array[0]);
	for (index = 1; index < size; index++)
		heap_insert(&rootNode, array[index]);

	return (rootNode);
}
