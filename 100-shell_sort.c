#include "sort.h"

/**
 * swap_integers - Switches the positions of two integers in an array.
 * @a: Pointer to the first integer to swap.
 * @b: Pointer to the second integer to swap.
 */
void swap_integers(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Arranges an array of integers in ascending order utilizing
 *              the shell sort method.
 * @array: Pointer to the array of integers.
 * @size: The total number of elements in the array.
 *
 * Description: Implements the shell sort algorithm with
 *	the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	gap = 1;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_integers(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
		gap /= 3;
	}
}
