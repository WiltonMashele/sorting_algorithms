#include "sort.h"

void merge_parts(int *array, int *temp, size_t start, size_t middle, size_t end);
void merge_sort_while(int *array, int *temp, size_t start, size_t end);
void merge_sort(int *array, size_t size);

/**
 * merge_parts - Merges two partitions of an array.
 * @array: Pointer to an integer array.
 * @temp: A temporary buffer for storing the merged array.
 * @start: The starting index of the first partition.
 * @middle: The ending index of the first partition.
 * @end: The ending index of the second partition.
 */
void merge_parts(int *array, int *temp, size_t start, size_t middle, size_t end)
{
	size_t leftIndex = start, rightIndex = middle, tempIndex = 0;

	printf("Merging...\n[left]: ");
	print_array(array + start, middle - start);

	printf("[right]: ");
	print_array(array + middle, end - middle);

	while (leftIndex < middle && rightIndex < end)
	{
		if (array[leftIndex] < array[rightIndex])
			temp[tempIndex++] = array[leftIndex++];
		else
			temp[tempIndex++] = array[rightIndex++];
	}

	while (leftIndex < middle) temp[tempIndex++] = array[leftIndex++];
	while (rightIndex < end) temp[tempIndex++] = array[rightIndex++];

	for (size_t i = start; i < end; i++) array[i] = temp[i - start];

	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * merge_sort_while - Sorts a subarray iteratively.
 * @array: Pointer to an integer array to sort.
 * @temp: A temporary buffer for storing the merged array.
 * @start: The starting index of the array.
 * @end: The ending index of the array.
 */
void merge_sort_while(int *array, int *temp, size_t start, size_t end)
{
	size_t size = end - start;

	for (size_t width = 1; width < size; width *= 2)
	{
		for (size_t i = start; i < end; i += 2 * width)
		{
			size_t middle = i + width < end ? i + width : end;
			size_t finish = i + 2 * width < end ? i + 2 * width : end;
			merge_parts(array, temp, i, middle, finish);
		}
	}
}

/**
 * merge_sort - Executes merge sort on an integer array.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description: Executes merge sort using an iterative method.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_while(array, temp, 0, size);

	free(temp);
}
