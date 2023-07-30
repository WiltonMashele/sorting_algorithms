#include "sort.h"

int find_maximum(int *array, int size);
void sort_by_digit(int *array, size_t size, int digit, int *tempBuffer);
void radix_sort(int *array, size_t size);

/**
 * find_maximum - Finds the largest integer within the given array.
 * @array: Pointer to the array of integers.
 * @size: Number of elements in the array.
 *
 * Return: The largest integer found in the array.
 */
int find_maximum(int *array, int size)
{
	int max_value = array[0];
	int i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	return max_value;
}

/**
 * sort_by_digit - Performs counting sort based on the significant digit.
 * @array: Pointer to the array of integers.
 * @size: Number of elements in the array.
 * @digit: The digit place to sort on.
 * @tempBuffer: Temporary buffer to hold sorted integers.
 */
void sort_by_digit(int *array, size_t size, int digit, int *tempBuffer)
{
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / digit) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
		tempBuffer[count[(array[i - 1] / digit) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / digit) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = tempBuffer[i];
}

/**
 * radix_sort - Applies the LSD radix sort algorithm to an array of integers.
 * @array: Pointer to the array of integers.
 * @size: Number of elements in the array.
 *
 * Description: This function uses the radix sort method to sort the given
 * array. It prints the array after sorting each digit.
 */
void radix_sort(int *array, size_t size)
{
	int max_value, digit;
	int *tempBuffer;

	if (array == NULL || size < 2)
		return;

	tempBuffer = (int *)malloc(sizeof(int) * size);
	if (tempBuffer == NULL)
		return;

	max_value = find_maximum(array, size);

	for (digit = 1; max_value / digit > 0; digit *= 10)
	{
		sort_by_digit(array, size, digit, tempBuffer);
		print_array(array, size);
	}

	free(tempBuffer);
}
