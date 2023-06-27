#include "sort.h"


/**
 * swap - Swaps two elements of an array.
 * @a: The first element
 * @b: The second element
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}


/**
 * lumoto_partition - Implements the lumoto partitioning on an array.
 * @array: The array to be worked on.
 * @lb: The lower boundary of the array.
 * @ub: The upper boundary of the array.
 * @size: The full size of the array
 *
 * Return: The index of the pivot.
 */

int lumoto_partition(int *array, int lb, int ub, size_t size)
{
	int pivot = array[ub], i = lb - 1, j;

	for (j = lb; j < ub; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[ub]);
	print_array(array, size);

	return (i + 1);
}


/**
 * quick_sort_helper - Implements the quicksort algorithm by recursively
 *		calling itself on the sub aarrays before and after pivot
 * @array: The array to be sorted.
 * @lb: The lower boundary of the array/sub array to be sorted
 * @ub: The upper boundary of the array/ sub-array to be sorted
 * @size: The full size of the array
 */
void quick_sort_helper(int *array, int lb, int ub, size_t size)
{
	int pivot_index;

	if (lb < ub)
	{
		pivot_index = lumoto_partition(array, lb, ub, size);
		quick_sort_helper(array, lb, pivot_index - 1, size);
		quick_sort_helper(array, pivot_index + 1, ub, size);
	}
}


/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick
 *		sort algorithm
 * @array: A pointer to the array to be sorted.
 * @size: The size of the array to be sorted.
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1, size);
}
