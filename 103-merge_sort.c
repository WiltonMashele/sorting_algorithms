#include "sort.h"

void combine_segments(int *segment, int *temp, size_t start, size_t middle, size_t end);
void sort_recursive(int *segment, int *temp, size_t start, size_t end);
void perform_merge_sort(int *arr, size_t length);

/**
 * combine_segments - Merge parts of an array of integers.
 * @segment: A segment of an array of integers to be merged.
 * @temp: A temporary buffer to keep the merged result.
 * @start: The beginning index of the array segment.
 * @middle: The central index of the array segment.
 * @end: The ending index of the array segment.
 */
void combine_segments(int *segment, int *temp, size_t start, size_t middle, size_t end)
{
	size_t a, b, c = 0;

	printf("Combining segments...\n[Left]: ");
	print_array(segment + start, middle - start);

	printf("[Right]: ");
	print_array(segment + middle, end - middle);

	for (a = start, b = middle; a < middle && b < end; c++)
		temp[c] = (segment[a] < segment[b]) ? segment[a++] : segment[b++];
	for (; a < middle; a++)
		temp[c++] = segment[a];
	for (; b < end; b++)
		temp[c++] = segment[b];
	for (a = start, c = 0; a < end; a++)
		segment[a] = temp[c++];

	printf("[Finished]: ");
	print_array(segment + start, end - start);
}

/**
 * sort_recursive - Perform recursive merge sort on a segment of integers.
 * @segment: A segment of an array of integers to sort.
 * @temp: A temporary buffer to hold the sorted segment.
 * @start: The beginning index of the segment.
 * @end: The ending index of the segment.
 */
void sort_recursive(int *segment, int *temp, size_t start, size_t end)
{
	size_t middle;

	if (end - start > 1)
	{
		middle = start + (end - start) / 2;
		sort_recursive(segment, temp, start, middle);
		sort_recursive(segment, temp, middle, end);
		combine_segments(segment, temp, start, middle, end);
	}
}

/**
 * perform_merge_sort - Order an array of integers in ascending
 *                      fashion utilizing the merge sort technique.
 * @arr: An array of integers.
 * @length: The length of the array.
 *
 * Description: Applies the top-down variation of merge sort.
 */
void perform_merge_sort(int *arr, size_t length)
{
	int *temp;

	if (arr == NULL || length < 2)
		return;

	temp = malloc(sizeof(int) * length);
	if (temp == NULL)
		return;

	sort_recursive(arr, temp, 0, length);

	free(temp);
}
