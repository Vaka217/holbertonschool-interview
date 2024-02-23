#ifndef SORT_H
#define SORT_H

#define MAX 2000

#include <stdlib.h>
#include <stdio.h>

void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void join(size_t size, int *array, int *right, int *left);

#endif
