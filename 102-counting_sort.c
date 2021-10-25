#include "sort.h"
#include <stdlib.h>


/**
 * counting_sort - performs counting sort on an array
 * @array: an integer array
 * @size: size of `array`
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *arr = NULL, j = 0, k = 0;
	unsigned int i = 0, max = 0;

	if (array == NULL || !size)
		return;
	for (i = 0; i < size; ++i)
		if ((unsigned int)array[i] > max)
			max = array[i];
	arr = malloc(sizeof(int) * (max + 1));
	for (i = 0; i < max + 1; ++i)
		arr[i] = 0;
	for (i = 0; i < size; ++i)
		arr[array[i]] += 1;

	for (i = 0; i < max + 1; ++i)
		if (arr[i])
			for (j = 0; j < arr[i]; ++j)
				array[k++] = i;
	print_array(arr, max + 1);
	free(arr);
}
