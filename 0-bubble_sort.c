#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order.
 *
 *
 *
 *
 *
 *
 *
 */


void bubble_sort(int *array, size_t size)
{
	unsigned int temp;
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			 if (array[j] > array[i])
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}

		}
	}
}
