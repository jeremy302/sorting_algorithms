#include "sort.h"

/**
 * heapTrio - turns a single node into a heap
 * @array: binary tree
 * @size: size of `array`
 * @limit: size of binary tree
 * @parent: parent node
 *
 * Return: 0 for no change, 1 if the left child node was the biggest, else 2
 */
int heapTrio(int *array, size_t size, size_t limit, int parent)
{
	int tmp, v1_i = parent * 2 + 1, v2_i = v1_i + 1,
		*v1 = v1_i < (int)limit ? array + v1_i : NULL,
		*v2 = v2_i < (int)limit ? array + v2_i : NULL,
		*max = v1 == NULL ? NULL : v2 == NULL ? v1 : *v1 >= *v2 ? v1 : v2;

	if (max != NULL && array[parent] <= *max)
	{
		tmp = array[parent];
		array[parent] = *max;
		*max = tmp;
		print_array(array, size);
		return (1 + (max == v2));
	}
	return (0);
}

/**
 * siftDown - performs a sift-down operation a node
 * @array: binary tree
 * @size: size of `array`
 * @limit: size of binary tree
 * @parent: node parent
 *
 * Return: void
 */
inline void siftDown(int *array, size_t size, size_t limit, int parent)
{
	int j = 0, n = 0;

	for (j = parent; j * 2 + 1 < (int)limit; j = j * 2 + (n + (!n)))
		n = heapTrio(array, size, limit, j);
}

/**
 * heapTree - turns a complete binary tree into a heap
 * @array: binary tree
 * @size: size of `array`
 *
 * Return: void
 */
inline void heapTree(int *array, size_t size)
{
	int i = 0;

	for (i = size / 2 - 1; i >= 0; --i)
		siftDown(array, size, size, i);
}

/**
 * heap_sort - performs heap sort on an array
 * @array: an integer array
 * @size: size of `array`
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int i = 0, tmp;

	if (array == NULL || size < 2)
		return;
	heapTree(array, size);
	for (i = 0; i < (int)size; ++i)
	{
		tmp = array[size - i - 1];
		array[size - i - 1] = array[0];
		array[0] = tmp;
		if (tmp != array[size - i - 1])
			print_array(array, size);
		siftDown(array, size, size - i - 1, 0);
	}
}
