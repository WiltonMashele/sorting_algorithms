#include "sort.h"

/**
 * swap_ints - Swaps the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - Rearranges a subset of an integer array according to a given
 * scheme.
 * @array: The array being targeted.
 * @size: The size of the array.
 * @left: The starting index of the subset.
 * @right: The ending index of the subset.
 * Return: The index of the partition.
 */
int partition(int *array, size_t size, int left, int right)
{
	int *pivot = array + right;
	int above = left, below = left;

	while (below < right)
	{
		if (array[below] < *pivot)
		{
			if (above != below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
		below++;
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * quick_sort - Organizes integers by utilizing quicksort and a partitioning
 * method.
 * @array: A pointer to the integer array.
 * @size: The total number of elements within the array.
 * Note: The array is printed after each individual element is swapped.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL && size >= 2)
	{
		partition(array, size, 0, size - 1);
	}
}
