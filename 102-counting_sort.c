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
	int *arr = NULL, _arr_iv = 0, j = 0, k = 0, prv, cur;
	unsigned int i = 0, max = 0;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; ++i)
		if ((unsigned int)array[i] > max)
			max = array[i];
	arr = malloc(sizeof(int) * (max + 1));
	if (arr == NULL)
		return;
	for (i = 0; i < max + 1; ++i)
		arr[i] = 0;
	for (i = 0; i < size; ++i)
		arr[array[i]] += 1;

	for (i = 0; i < max + 1; ++i)
	{
		(void) _arr_iv, (void) j;
		_arr_iv = arr[i];
		arr[i] = arr[i] + (i ? arr[i - 1] : 0);
	}

	for (k = 0, i = 0; i < max + 1; ++i)
	{
		prv = i > 0 ? arr[i - 1] : 0;
		cur = arr[i];
		for (j = prv; j < cur; ++j)
			array[k++] = i;
	}
	print_array(arr, max + 1);
	free(arr);
}
