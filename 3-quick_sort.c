#include "sort.h"

/**
 * swap_elements - swaps the values of two integers.
 * @x: pointer to the first integer.
 * @y: pointer to the second integer.
 * @array: array of integers.
 * @size: size of the array.
 **/
void swap_elements(int *array, int *x, int *y, size_t size)
{
	int temp = *x;
	*x = *y;
	*y = temp;
	print_array(array, size);
}

/**
 * hoare_partition - Hoare partition scheme for the array.
 * @array: array of integers.
 * @low: lower index.
 * @high: higher index.
 * @size: size of the array.
 * Return: partition index.
 **/
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[low];
	int left = low - 1;
	int right = high + 1;

	while (true)
	{
		do
		{
			left++;
		} while (array[left] < pivot);

		do
		{
			right--;
		} while (array[right] > pivot);

		if (left >= right)
			return right;

		swap_elements(array, &array[left], &array[right], size);
	}
}

/**
 * recursive_quick_sort - recursive function to perform quick sort.
 * @array: array of integers.
 * @low: lower index.
 * @high: higher index.
 * @size: size of the array.
 **/
void recursive_quick_sort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int partition_index = hoare_partition(array, low, high, size);
		recursive_quick_sort(array, low, partition_index, size);
		recursive_quick_sort(array, partition_index + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order.
 * @array: array of integers.
 * @size: size of the array.
 **/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	recursive_quick_sort(array, 0, size - 1, size);
}
