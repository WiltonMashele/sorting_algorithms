#include "sort.h"

/**
 * swap_elements - Interchange the positions of two integers in an array.
 * @first: Pointer to the first integer.
 * @second: Pointer to the second integer.
 */
void swap_elements(int *first, int *second)
{
	int temporary;

	temporary = *first;
	*first = *second;
	*second = temporary;
}

/**
 * selection_sort - Sorts an integer array in ascending order using 
 *                  the selection sort method.
 * @array: Pointer to an array of integers.
 * @size: The number of elements in the array.
 *
 * Description: The function displays the array after each successful swap.
 */
void selection_sort(int *array, size_t size)
{
	int *minimum_value;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minimum_value = &array[i];
		for (j = i + 1; j < size; j++)
			minimum_value = (array[j] < *minimum_value) ? &array[j] : minimum_value;

		if (&array[i] != minimum_value)
		{
			swap_elements(&array[i], minimum_value);
			print_array(array, size);
		}
	}
}
