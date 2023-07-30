#include "sort.h"

void exchange_elements(int *element1, int *element2);
int hoare_partition_scheme(int *array, size_t size, int start, int end);
void recursive_quick_sort(int *array, size_t size, int start, int end);
void quick_sort_hoare(int *array, size_t size);

/**
 * exchange_elements - Switches the places of two integers in the array.
 * @element1: The first integer to be swapped.
 * @element2: The second integer to be swapped.
 */
void exchange_elements(int *element1, int *element2)
{
	int temporary;

	temporary = *element1;
	*element1 = *element2;
	*element2 = temporary;
}

/**
 * hoare_partition_scheme - Organizes a subset of an array of integers
 *                          using the hoare partitioning method.
 * @array: The array of integers.
 * @size: The size of the array.
 * @start: The initial index of the subset to be organized.
 * @end: The final index of the subset to be organized.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition_scheme(int *array, size_t size, int start, int end)
{
	int pivot, lower, higher;

	pivot = array[end];
	for (lower = start - 1, higher = end + 1; lower < higher;)
	{
		do {
			lower++;
		} while (array[lower] < pivot);
		do {
			higher--;
		} while (array[higher] > pivot);

		if (lower < higher)
		{
			exchange_elements(array + lower, array + higher);
			print_array(array, size);
		}
	}

	return (lower);
}

/**
 * recursive_quick_sort - Applies the quicksort algorithm recursively.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @start: The initial index of the array partition to organize.
 * @end: The final index of the array partition to organize.
 *
 * Description: Uses the Hoare partition scheme.
 */
void recursive_quick_sort(int *array, size_t size, int start, int end)
{
	int partition;

	if (end - start > 0)
	{
		partition = hoare_partition_scheme(array, size, start, end);
		recursive_quick_sort(array, size, start, partition - 1);
		recursive_quick_sort(array, size, partition, end);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending
 *                    order by applying the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after every exchange of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_quick_sort(array, size, 0, size - 1);
}
