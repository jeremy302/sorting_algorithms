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
	unsigned int i = 0, j = 0;
	char sorted = 1;

	if (array != NULL)
		do
			for (sorted = 1, i = 0, ++j; i < size - j; ++i)
				if (array[i] > array[i + 1])
				{
					sorted = 0;
					tmp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = tmp;
					print_array(array, size);
				}
		while (!sorted);
}
