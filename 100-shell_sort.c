#include "sort.h"


/**
 * shell_sort - performs shell sort on an array
 * @array: an integer array
 * @size: size of `array`
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	char sorted = 0;
	unsigned int tmp, i = 0, j = 0, k = 0,
		K = 1, KN = ((size / 3) * 2) + 1, pow_3 = 3;

	while (pow_3 <= KN)
		pow_3 *= 3, ++K;
	if (array == NULL)
		return;
	for (; K > 0; --K, pow_3 /= 3)
	{
		k = (pow_3 - 1) / 2;
		for (i = 0; i < k; ++i)
			do {
				for (sorted = 1, j = i; j + k < size; j += k)
					if (array[j] > array[j + k])
					{
						sorted = 0;
						tmp = array[j];
						array[j] = array[j + k];
						array[j + k] = tmp;
					}
			} while (!sorted);
		print_array(array, size);
	}
}
