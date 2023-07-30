#include "sort.h"

/**
 * find_max - Determines the largest value in an integer array.
 * @array: Pointer to an array of integers.
 * @size: The number of elements in the array.
 *
 * Return: The largest integer value within the array.
 */
int find_max(int *array, int size)
{
	int max = array[0];
	int i = 1;

	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}

	return max;
}

/**
 * counting_sort - Implements the counting sort algorithm to sort an integer array in
 *                 non-descending order.
 * @array: Pointer to an array of integers.
 * @size: The number of elements in the array.
 *
 * Description: This function also prints the counting array after initializing it.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max;
	int i = 0;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;

	max = find_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	while (i < (max + 1))
	{
		count[i] = 0;
		i++;
	}

	i = 0;
	while (i < (int)size)
	{
		count[array[i]] += 1;
		i++;
	}

	i = 1;
	while (i < (max + 1))
	{
		count[i] += count[i - 1];
		i++;
	}
	print_array(count, max + 1);

	i = 0;
	while (i < (int)size)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
		i++;
	}

	i = 0;
	while (i < (int)size)
	{
		array[i] = sorted[i];
		i++;
	}

	free(sorted);
	free(count);
}
