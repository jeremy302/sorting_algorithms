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
		do {
			sorted = 1;
			for (i = 0, j = 0; i < size - 1 - j; ++i)
				if (array[i] > array[i + 1])
				{
					sorted = 0;
					tmp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = tmp;
					print_array(array, size);
				}
			++j;
		} while (!sorted);
}
