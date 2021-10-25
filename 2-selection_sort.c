#include "sort.h"


/**
 * selection_sort - performs selection sort on an array
 * @array: an integer array
 * @size: size of `array`
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int tmp;
	unsigned int i = 0, j = 0, ind = 0;

	if (array != NULL)
		for (i = 0; i < size; ind = ++i)
		{
			for (j = i; j < size; ++j)
				if (array[j] < array[ind])
					ind = j;
			tmp = array[i];
			array[i] = array[ind];
			array[ind] = tmp;
			if (i != ind)
				print_array(array, size);
		}
}
