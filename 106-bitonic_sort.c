#include "sort.h"

/**
 * bsort - recursive function for bitonic sort
 * @array: array to sort
 * @size: size of `array`
 * @lo: partition lower bound
 * @hi: partition higher bound
 * @asc: whether to sort in ascending or descending order
 *
 * Return: void
 */
void bsort(int *array, size_t size, int lo, int hi, char asc)
{
	int tmp, i = 0,
		df = hi + 1 - lo, md = lo + df / 2, gap = 1, g = 0, pow_2 = 1;


	if (df < 2)
		return;
	printf("Merging [%d/%ld] (%s):\n", df, size, asc ? "UP" : "DOWN");
	print_array(array + lo, df);

	bsort(array, size, lo, md - 1, 1);
	bsort(array, size, md, hi, 0);

	while (pow_2 < df) /* confirm later */
		gap *= 2, pow_2 *= 2;
	for (g = gap; g >= 1; --g)
		for (i = lo; i + g <= hi; ++i)
			if (asc ? array[i] > array[i + g] : array[i] < array[i + g])
			{
				tmp = array[i];
				array[i] = array[i + g];
				array[i + g] = tmp;
			}
	printf("Result [%d/%ld] (%s):\n", df, size, asc ? "UP" : "DOWN");
	print_array(array + lo, df);
}


/**
 * bitonic_sort - performs bitonic sort on an array
 * @array: an integer array
 * @size: size of `array`
 *
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bsort(array, size, 0, size - 1, 1);
}
