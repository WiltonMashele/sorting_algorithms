#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort - Function to initiate merge sort on an integer array.
 * @array: Pointer to the integer array to be sorted.
 * @size: Number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t index;
	int *temp_array;

	if (array == NULL || size < 2) return;

	temp_array = malloc(sizeof(int) * size);
	if (temp_array == NULL) return;

	for (index = 0; index < size; index++) {
		temp_array[index] = array[index];
	}

	merge_partition(0, size, array, temp_array);
	free(temp_array);
}

/**
 * merge - Merges two sorted subarrays into one.
 * @lo: Start index of the first subarray.
 * @mi: Start index of the second subarray.
 * @hi: End index of the second subarray.
 * @dest: Pointer to destination array.
 * @src: Pointer to source array.
 */
void merge(size_t lo, size_t mi, size_t hi, int *dest, int *src)
{
	size_t i = lo, j = mi, k = lo;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(src + lo, mi - lo);
	printf("[right]: ");
	print_array(src + mi, hi - mi);

	while (k < hi) {
		if (i < mi && (j >= hi || src[i] <= src[j])) {
			dest[k++] = src[i++];
		} else {
			dest[k++] = src[j++];
		}
	}
	printf("[Done]: ");
	print_array(dest + lo, hi - lo);
}

/**
 * merge_partition - Recursively divides array and sorts.
 * @lo: Start index of current array partition.
 * @hi: End index of current array partition.
 * @array: Pointer to array being sorted.
 * @base: Pointer to a temporary array.
 */
void merge_partition(size_t lo, size_t hi, int *array, int *base)
{
	size_t mi;

	if (hi - lo < 2) return;

	mi = (lo + hi) / 2;
	merge_partition(lo, mi, array, base);
	merge_partition(mi, hi, array, base);
	merge(lo, mi, hi, array, base);

	for (mi = lo; mi < hi; mi++) {
		base[mi] = array[mi];
	}
}
