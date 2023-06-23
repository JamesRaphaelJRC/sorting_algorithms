#include "sort.h"


/**
 * bubble_sort - Sorts an array of integers in ascending order using the Bubble
 *		sort algorithm
 * @array: A pointer to the array to be sorted.
 * @size: The number of elements in thee array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, next, count = 0;

	if (size < 2)
		return;

	while (count < size)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				next = array[i];
				array[i] = array[i + 1];
				array[i + 1] = next;
				print_array(array, size);
			}
		}
		count++;
	}
}
