/*
 * File: 2-selection_sort.c
 * Auth: Sess254
 */

#include "sort.h"

/**
 * selection_sort - sorts an array of ints  using selection sort
 * @array: array to sort
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0, min = 0;
	int *swap = NULL;

	if (!array || size < 2)
		return;
	for (; i < size; i++)
	{
		min = i;
		swap = malloc(sizeof(int) * 1);
		*swap = *(array + i);
		for (j = i + 1; j < size; j++)
		{
			if (*(array + j) < *(array + min))
			{
				min = j;
			}
		}
		if (i < min)
		{
			*(array + i) = *(array + min);
			*(array + min) = *swap;
			free(swap);
			print_array(array, size);
		}
		else
			free(swap);
	}
}
