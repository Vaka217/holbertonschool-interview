#ifndef _SORT_H_
#define _SORT_H_

#include <stddef.h>
#include <stdio.h>

void swap(int *x, int *y);
void heapify(int *array, size_t size, int i, size_t len);
void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);

#endif /* _SORT_H_ */
