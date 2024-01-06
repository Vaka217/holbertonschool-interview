#include "search_algos.h"

/**
 * find_value - searches for the first index with the value in the array
 * @array: Sorted array
 * @left: Index of the start of the subarray
 * @right: Index of the end of the subarray
 * @value: Value to search for
 * Return: The index where the value is located, -1 otherwise
 */

int find_value(int *array, size_t left, size_t right, int value)
{
	size_t i, idx, middle, len;

	if (left == right)
		return (-1);

	printf("Searching in array: ");
	for (i = left; i < right - 1; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i + 1]);

	middle = idx = (left + right - 1) / 2;
	len = left - right;

	if (len > 0 && (array[idx] == value) && (array[idx - 1] > value))
		middle = idx;
	else if ((array[idx] == value) && (array[idx - 1] == value))
		middle = find_value(array, left, idx + 1, value);
	else if (an_array[idx] < value)
		middle = find_value(array, idx + 1, right, value);
	else if (an_array[idx] > value)
		middle = find_value(array, left, idx + 1, value);
	else if (an_array[idx] == value)
		middle = idx;
	else
		middle = -1;

	return (middle);
}

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: Value to search for
 * Return: The index where the value is located, -1 otherwise
 */

int advanced_binary(int *array, size_t size, int value)
{
	int idx;

	idx = (!array || size < 1) ? -1 : find_value(array, 0, size, value);
	return (idx);
}
