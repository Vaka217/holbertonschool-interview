#include "search_algos.h"
#include <stdio.h>

int advanced_binary(int *array, size_t size, int value)
{
	size_t i;
	int m, result;

	m = size / 2;

	if (size == 1 && array[m] == value)
		return (m);

	printf("Searching in array: ");
	for (i = 0; i < size - 1; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[size - 1]);

	if (size == 1)
		return (-1);

	if (array[m] == value)
		return (m);
	else if (array[m] > value)
		return (advanced_binary(array, m, value));

	if (size % 2 == 0)
		m--;
	result = advanced_binary(array + m + 1, size - m - 1, value);
	return ((result == -1) ? -1 : m + 1 + result);
}
