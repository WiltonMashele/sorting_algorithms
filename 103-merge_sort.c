#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort - Function to sort an array using the merge sort algorithm.
 * @array: The array that needs to be sorted.
 * @size: Number of elements in the array.
 * Returns: None.
 */
void merge_sort(int *array, size_t size)
{
	size_t idx = 0;
	int *tempArray = NULL;

	if (array == NULL || size < 2)
		return;
	tempArray = malloc(sizeof(int) * size);
	if (tempArray == NULL)
		return;
	for (idx = 0; idx < size; idx++)
		tempArray[idx] = array[idx];
	split_and_merge(0, size, array, tempArray);
	free(tempArray);
}

/**
 * merge - Function to merge sorted subarrays.
 * @start: Start index.
 * @middle: Middle index.
 * @end: End index.
 * @destination: Array to store sorted elements.
 * @source: Original array.
 * Returns: None.
 */
void merge(size_t start, size_t middle, size_t end, int *destination, int *source)
{
	size_t i = start, j = middle, k = start;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, middle - start);
	printf("[right]: ");
	print_array(source + middle, end - middle);
	for (k = start; k < end; k++)
	{
		if (i < middle && (j >= end || source[i] <= source[j]))
		{
			destination[k] = source[i++];
		}
		else
		{
			destination[k] = source[j++];
		}
	}
	printf("[Done]: ");
	print_array(destination + start, end - start);
}

/**
 * split_and_merge - Function that divides the array and sorts recursively.
 * @start: Start index.
 * @end: End index.
 * @array: Array to be sorted.
 * @tempArray: Temporary array to store values.
 * Returns: None.
 */
void split_and_merge(size_t start, size_t end, int *array, int *tempArray)
{
	size_t middle;

	if (end - start < 2)
		return;
	middle = (start + end) / 2;
	split_and_merge(start, middle, array, tempArray);
	split_and_merge(middle, end, array, tempArray);
	merge(start, middle, end, array, tempArray);
	for (middle = start; middle < end; middle++)
		tempArray[middle] = array[middle];
}
