#include "sort.h"


/**
 * selection_sort - Sorts an array of integers in ascending order using the
 *			Selection sort algorithm
 * @array: The array to be sorted.
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min, min_index, tmp;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		j = i + 1;

		for (; j < size; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				min_index = j;
			}
		}
		tmp = array[i];
		array[i] = min;
		array[min_index] = tmp;

		print_array(array, size);
	}
}
