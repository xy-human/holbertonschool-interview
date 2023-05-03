#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, int l, int r);

int binary_recursive(int *array, int l, int r, int value);

int advanced_binary(int *array, size_t size, int value);

#endif
