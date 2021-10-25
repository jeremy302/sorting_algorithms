#include "sort.h"
#include <stdlib.h>

#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))

/**
 * msort - recursive function for mergesort
 * @array: an array
 * @lo: partition lower bound (inclusive)
 * @hi: partition upper bound (inclusive)
 * @arr_tmp: buffer for rearrangement
 *
 * Return: void
 */
void msort(int *array, int lo, int hi, int *arr_tmp)
{
	int i = 0, j = 0, k = 0, md = ((hi - 1) - lo) / 2 + lo;

	if (hi != lo)
	{
		msort(array, lo, md, arr_tmp);
		msort(array, min(hi, md + 1), hi, arr_tmp);
	}
	else
		return;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + lo, (md - lo) + 1);
	printf("[right]: ");
	print_array(array + md + 1, (hi - (md + 1)) + 1);

	j = lo;
	k = md + 1;
	for (i = lo; i <= hi; ++i)
	{
		if (j > md)
			arr_tmp[i] = array[k++];
		else if (k > hi)
			arr_tmp[i] = array[j++];
		else
		{
			if (array[j] < array[k])
				arr_tmp[i] = array[j++];
			else
				arr_tmp[i] = array[k++];
		}
	}
	for (i = lo; i <= hi; ++i)
		array[i] = arr_tmp[i];
	printf("[Done]: ");
	print_array(array + lo, (hi - lo) + 1);
}

/**
 * merge_sort - performs merge sort on an array
 * @array: an integer array
 * @size: size of `array`
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *arr_tmp = NULL;

	if (array == NULL || !size)
		return;

	arr_tmp = malloc(sizeof(int) * size);
	msort(array, 0, size - 1, arr_tmp);
	free(arr_tmp);
}
