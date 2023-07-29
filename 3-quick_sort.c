#include "sort.h"

/**
 * swap_elements - Swaps two integers in an array.
 * @arr: The array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 * @sz: The size of the array.
 */
void swap_elements(int *arr, int *a, int *b, size_t sz)
{
	int temp = *a;

	*a = *b;
	*b = temp;
	print_array(arr, sz);
}

/**
 * partition_array - Partitions the array for quicksort.
 * @arr: The array.
 * @start: The starting index.
 * @end: The ending index.
 * @sz: The size of the array.
 * Return: Number of changes made.
 */
int partition_array(int *arr, int start, int end, size_t sz)
{
	int pivotValue = arr[end];
	int pivotIndex = start;
	int iter;

	for (iter = start; iter < end; iter++)
	{
		if (arr[iter] <= pivotValue)
		{
			if (pivotIndex != iter)
				swap_elements(arr, &arr[iter], &arr[pivotIndex], sz);
			pivotIndex++;
		}
	}
	if (pivotIndex != end)
		swap_elements(arr, &arr[end], &arr[pivotIndex], sz);

	return pivotIndex;
}

/**
 * perform_quickSort - Performs the quicksort algorithm.
 * @arr: The array.
 * @start: The starting index.
 * @end: The ending index.
 * @sz: The size of the array.
 */
void perform_quickSort(int *arr, int start, int end, size_t sz)
{
	int partitionIndex;

	if (start < end)
	{
		partitionIndex = partition_array(arr, start, end, sz);
		perform_quickSort(arr, start, partitionIndex - 1, sz);
		perform_quickSort(arr, partitionIndex + 1, end, sz);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using quicksort.
 * @array: The array.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	perform_quickSort(array, 0, size - 1, size);
}
