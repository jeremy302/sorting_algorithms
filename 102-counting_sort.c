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
	int *arr = NULL, _arr_iv = 0, j = 0;
	unsigned int i = 0, max = 0;

	if (array == NULL || size < 2)
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
	{
		_arr_iv = arr[i];
		arr[i] = arr[i] + (i ? arr[i - 1] : 0);
		for (j = arr[i] - 1; j >= 0 && (int)j < (arr[i] - 1) + _arr_iv; ++j)
			array[j] = i;
	}
	print_array(arr, max + 1);
	free(arr);
}
