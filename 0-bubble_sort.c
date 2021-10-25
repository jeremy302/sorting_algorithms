#include "sort.h"


/**
 * bubble_sort - performs bubble sort on an array
 * @array: an integer array
 * @size: size of `array`
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	unsigned int i = 0, j = 1, _j = 1;

	if (array != NULL)
		do {
			for (i = 0; i < size - j; ++i)
				if (array[i] > array[i + 1])
				{
					_j = size - i;
					tmp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = tmp;
					print_array(array, size);
				}
			j = _j;
		} while (size - j >= 1);
}
