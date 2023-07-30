#include "sort.h"

void combine_arrays(int *partial, int *temp, size_t start, size_t middle, size_t end);
void recursive_merge_sort(int *partial, int *temp, size_t start, size_t end);
void merge_sort(int *array, size_t size);

/**
 * combine_arrays - Combine two sorted arrays into one sorted array.
 * @partial: A part of the array that needs to be sorted.
 * @temp: Temporary storage for the sorting process.
 * @start: The starting index of the first array.
 * @middle: The ending index of the first array and starting index of the second array.
 * @end: The ending index of the second array.
 */
void combine_arrays(int *partial, int *temp, size_t start, size_t middle, size_t end)
{
	size_t i, j, k = 0;

	printf("Combining...\n[Left]: ");
	print_array(partial + start, middle - start);

	printf("[Right]: ");
	print_array(partial + middle, end - middle);

	for (i = start, j = middle; i < middle && j < end; k++)
		temp[k] = (partial[i] < partial[j]) ? partial[i++] : partial[j++];
	while (i < middle)
		temp[k++] = partial[i++];
	while (j < end)
		temp[k++] = partial[j++];
	for (i = start, k = 0; i < end; i++)
		partial[i] = temp[k++];

	printf("[Completed]: ");
	print_array(partial + start, end - start);
}

/**
 * recursive_merge_sort - A recursive method to implement merge sort.
 * @partial: A part of the array that needs to be sorted.
 * @temp: Temporary storage for the sorting process.
 * @start: The starting index of the part that needs to be sorted.
 * @end: The ending index of the part that needs to be sorted.
 */
void recursive_merge_sort(int *partial, int *temp, size_t start, size_t end)
{
	size_t middle;

	if (end - start > 1)
	{
		middle = start + (end - start) / 2;
		recursive_merge_sort(partial, temp, start, middle);
		recursive_merge_sort(partial, temp, middle, end);
		combine_arrays(partial, temp, start, middle, end);
	}
}

/**
 * merge_sort - Organize an array of integers in ascending
 *              order utilizing the merge sort technique.
 * @array: The array of integers that needs to be sorted.
 * @size: The length of the array.
 *
 * Note: This function follows the top-down approach of merge sort.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	recursive_merge_sort(array, temp, 0, size);

	free(temp);
}
