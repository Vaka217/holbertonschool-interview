#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swap two array elements
 * @x: Array element to swap with y
 * @y: Array element to swap with x
 */

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * heapify - Heapify on an array
 * @array: Array to heapify
 * @size: Array size
 * @i: Index of last non-leaf node
 * @len: Heap size
 */

void heapify(int *array, size_t size, int i, size_t len)
{
	int largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < len && array[left] > array[largest])
		largest = left;

	if (right < len && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, size, largest, len);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using
 * the Heap sort algorithm
 * @array: Array to sort
 * @size: Array size
 */

void heap_sort(int *array, size_t size)
{
	int i, start_idx = size / 2 - 1;

	for (i = start_idx; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, 0, i);
	}
}
