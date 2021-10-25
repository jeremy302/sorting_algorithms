#include "sort.h"


/**
 * qksort_hoare - recursive function for quicksort
 * @array: array to sort
 * @size: size of `array`
 * @lo: partition lower bound
 * @hi: partition higher bound
 *
 * Return: void
 */
void qksort_hoare(int *array, size_t size, int lo, int hi)
{
	int tmp, i = lo - 1, j = hi + 1, _p = hi, pivot = array[_p];

	if (lo >= hi)
		return;
	while (i < j)
	{
		while (array[++i] < pivot)
			continue;
		while (array[--j] > pivot)
			continue;
		_p = j - (j == hi);

		if (i < j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
	qksort_hoare(array, size, lo, _p);
	qksort_hoare(array, size, _p + 1, hi);
}


/**
 * quick_sort_hoare - performs quick sort on an array (hoare algorithm)
 * @array: an integer array
 * @size: size of `array`
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array != NULL && size > 1)
		qksort_hoare(array, size, 0, size - 1);
}
