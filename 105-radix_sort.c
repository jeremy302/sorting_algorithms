#include "sort.h"
#include <stdlib.h>


/**
 * radix_sort - performs radix sort on an array
 * @array: an integer array
 * @size: size of `array`
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int *arr = NULL, *arr_out = NULL, j = 0, div = 1, dig = 0, pos = 0;
	unsigned int i = 0, r = 0, max = 0, digs = 0, rad = 10;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; ++i)
		if ((unsigned int)array[i] > max)
			max = array[i];
	while (max != 0)
		max = max / 10, ++digs;
	arr = malloc(sizeof(int) * (rad + 1) + size);
	if (arr == NULL)
		return;
	arr_out = arr + rad + 1;
	for (r = 0; r < digs; ++r)
	{
		div = 1, dig = 0, pos = 0;
		for (i = 0; i < r; ++i)
			div *= 10;
		for (i = 0; i <= rad; ++i)
			arr[i] = 0;
		for (i = 0; i < size; ++i)
			arr_out[i] = 0;
		for (i = 0; i < size; ++i)
		{
			dig = (array[i] / div) % 10;
			arr[dig] += 1;
		}
		for (i = 0; i <= rad; ++i)
			arr[i] += (i ? arr[i - 1] : 0);
		for (j = size - 1; j >= 0; --j)
		{
			dig = (array[j] / div) % 10;
			pos = arr[dig];
			arr_out[pos - 1] = array[j];
			--arr[dig];
		}
		for (i = 0; i < size; ++i)
			array[i] = arr_out[i];
		print_array(array, size);
	}
	free(arr);
}
