#include "search_algos.h"

/**
 * print_array - print array integers
 * @array: an array of integers
 * @l: left value of the array
 * @r: right value of the array
 * Return: no return value
 */
void print_array(int *array, int l, int r)
{
	int i;

	printf("Searching in array: ");

	for (i = l; i < r; i++)
		printf("%d, ", array[i]);

	printf("%d\n", array[r]);
}

/**
 * binary_recursive - search for a value
 * @array: int array.
 * @l: left value of the array.
 * @r: right value of the array.
 * @value: value to search in the array.
 * Return: index of occurrence or -1 if not found or array is NULL.
 */
int binary_recursive(int *array, int l, int r, int value)
{
	int mid = l + (r - l) / 2;

	if (r >= l)
	{
		print_array(array, l, r);

		if (array[mid] == value)
		{
			if (array[mid - 1] == value && mid != 0)
				return (binary_recursive(array, l, mid, value));

			return (mid);
		}

		if (array[mid] >= value)
			return (binary_recursive(array, l, mid, value));

		return (binary_recursive(array, mid + 1, r, value));
	}

	return (-1);
}

/**
 * advanced_binary - binary function
 * @array: int array.
 * @size: size of array.
 * @value: value to search in the array.
 * Return: binary_recursive function return value
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (binary_recursive(array, 0, size - 1, value));
}
