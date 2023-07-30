#include "sort.h"

void exchange_values(int *x, int *y);
void build_max_heap(int *array, size_t total_size, size_t base_idx, size_t root_idx);
void heap_sort(int *array, size_t size);

/**
 * exchange_values - Exchange the values of two integers.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 */
void exchange_values(int *x, int *y)
{
	int temporary_value;

	temporary_value = *x;
	*x = *y;
	*y = temporary_value;
}

/**
 * build_max_heap - Convert a binary tree into a full binary heap.
 * @array: The array representing the binary tree.
 * @total_size: The full size of the array/tree.
 * @base_idx: Index representing the base row of the tree.
 * @root_idx: Index of the root node of the binary tree.
 */
void build_max_heap(int *array, size_t total_size, size_t base_idx, size_t root_idx)
{
	size_t left_idx, right_idx, largest_idx;

	left_idx = 2 * root_idx + 1;
	right_idx = 2 * root_idx + 2;
	largest_idx = root_idx;

	if (left_idx < base_idx && array[left_idx] > array[largest_idx])
		largest_idx = left_idx;
	if (right_idx < base_idx && array[right_idx] > array[largest_idx])
		largest_idx = right_idx;

	if (largest_idx != root_idx)
	{
		exchange_values(array + root_idx, array + largest_idx);
		print_array(array, total_size);
		build_max_heap(array, total_size, base_idx, largest_idx);
	}
}

/**
 * heap_sort - Implement the heap sort algorithm on an array of integers.
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Description: Sorts the provided array in ascending order using the
 * sift-down variation of the heap sort algorithm. The current state of
 * the array is printed after each swap operation.
 */
void heap_sort(int *array, size_t size)
{
	int idx;

	if (array == NULL || size < 2)
		return;

	for (idx = (size / 2) - 1; idx >= 0; idx--)
		build_max_heap(array, size, size, idx);

	for (idx = size - 1; idx > 0; idx--)
	{
		exchange_values(array, array + idx);
		print_array(array, size);
		build_max_heap(array, size, idx, 0);
	}
}
