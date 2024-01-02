#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: Value to search for
 * Return: The index where the value is located, -1 otherwise
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i;
	int m, result, first = -1;

	if (!array)
		return (-1);

	m = size / 2;

	if (size == 1 && array[m] == value)
		return (m);

	printf("Searching in array: ");
	for (i = 0; i < size - 1; i++)
	{
		if (array[i] == value && array[first] != value)
			first = i;
		printf("%d, ", array[i]);
	}
	printf("%d\n", array[size - 1]);

	if (size == 2 && array[m] == value)
	{
		if (array[m - 1] && array[m - 1] == value)
			return (m - 1);
		return (m);
	}

	if (size == 1)
		return (-1);

	if (size % 2 != 0 && array[m] == value)
		return (m);
	else if (array[m] > value || (array[m] >= value && m != first))
		return (advanced_binary(array, m, value));

	if (size % 2 == 0)
		m--;

	result = advanced_binary(array + m + 1, size - m - 1, value);
	return ((result == -1) ? -1 : m + 1 + result);
}
