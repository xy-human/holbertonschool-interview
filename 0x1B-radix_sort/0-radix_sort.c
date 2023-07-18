#include "sort.h"

/**
 * max_value - return the max value in array
 * @array: array
 * @size: size of the array
 * Return: return the max value in array
 */
int max_value(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * count_sort - sorts the array using the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 * @key: key
 */
void count_sort(int *array, int size, int key)
{
	int i = 0, count[10] = {0}, *output = NULL;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / key) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / key) % 10] - 1] = array[i];
		count[(array[i] / key) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
	print_array(array, size);
}

/**
 * radix_sort - function that sorts an array of integers using radix
 * @array: array to sort
 * @size: array size
 */
void radix_sort(int *array, size_t size)
{
	int base, max, i;

	if (array == NULL && size <= 1)
		return;

	max = max_value(array, size);

	for (i = 1, base = 10; max / i > 0; i *= base)
	{
		count_sort(array, size, i);
	}
}
