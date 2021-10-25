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
	int *arr = NULL, *arr_out = NULL, j = 0, num, pos;
	unsigned int i = 0, max = 0;

	if (array == NULL || !size)
		return;
	for (i = 0; i < size; ++i)
		if ((unsigned int)array[i] > max)
			max = array[i];
	arr = malloc(sizeof(int) * (max + 1 + size));
	if (arr == NULL)
		return;
	arr_out = arr + max + 1;
	for (i = 0; i < max + 1; ++i)
		arr[i] = 0;
	for (i = 0; i < size; ++i)
		arr[array[i]] += 1;

	for (i = 0; i < max + 1; ++i)
		arr[i] += i ? arr[i - 1] : 0;
	for (j = size - 1; j >= 0; --j)
	{
		num = array[j];
		pos = arr[num];
		arr_out[pos - 1] = array[j];
		--arr[num];
	}
	for (i = 0; i < size; ++i)
		array[i] = arr_out[i];
	print_array(arr, max + 1);
	free(arr);
}
