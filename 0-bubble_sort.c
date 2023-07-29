#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order.
 *
 * @array: the array to sort
 * @size: the size of the array
 */


void bubble_sort(int *array, size_t size)
{
	unsigned int i = 0;
	unsigned int j;
	int tmp;
	int swap_occurred;

	if (size < 2)
		return;

	do {
		swap_occurred = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
				swap_occurred = 1;
			}
		}
		i++;
	} while (swap_occurred);
}
