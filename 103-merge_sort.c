#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid, size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Combine a given segment of integers.
 * @subarr: A segment of an array of integers for merging.
 * @buff: A buffer to keep the merged segment.
 * @front: The starting index of the array segment.
 * @mid: The middle index of the array segment.
 * @back: The ending index of the array segment.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid, size_t back)
{
	size_t left, right, merge_idx;

	printf("Merging process...\n[Left]: ");
	print_array(subarr + front, mid - front);

	printf("[Right]: ");
	print_array(subarr + mid, back - mid);

	for (left = front, right = mid, merge_idx = 0; left < mid && right < back; merge_idx++)
		buff[merge_idx] = (subarr[left] < subarr[right]) ? subarr[left++] : subarr[right++];
	while (left < mid)
		buff[merge_idx++] = subarr[left++];
	while (right < back)
		buff[merge_idx++] = subarr[right++];
	for (left = front, merge_idx = 0; left < back; left++)
		subarr[left] = buff[merge_idx++];

	printf("[Completed]: ");
	print_array(subarr + front, back - front);
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
