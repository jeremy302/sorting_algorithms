#include "sort.h"


/**
 * qksort - recursive function for quicksort
 * @array: array to sort
 * @size: size of `array`
 * @lo: partition lower bound
 * @hi: partition higher bound
 *
 * Return: void
 */
void qksort(int *array, size_t size, int lo, int hi)
{
	int tmp, i = lo, j = lo, pivot = array[hi];

	if (lo >= hi)
		return;
	for (i = lo - 1, j = lo; j <= hi; j++)
		if (array[j] < pivot || j == hi)
		{
			tmp = array[++i];
			array[i] = array[j];
			array[j] = tmp;
			if (i != j)
				print_array(array, size);
		}
	qksort(array, size, lo, i - 1);
	qksort(array, size, i + 1, hi);
}

/**
 * quick_sort - performs quick sort on an array
 * @array: an integer array
 * @size: size of `array`
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
		qksort(array, size, 0, size - 1);
}
