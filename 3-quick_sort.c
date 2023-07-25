/*
 * File: 3-quick_sort.c
 * Auth: Sess254
 */

#include "sort.h"

void q_sort(int *array, ssize_t min, ssize_t max, size_t size);
size_t partition(int *array, ssize_t min, ssize_t max, size_t size);
/**
 *quick_sort - sorts array using quick sort algorithm
 *@array: array to sort
 *@size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	q_sort(array, 0, size - 1, size);
}

/**
 * q_sort - sorts the array of a partition recursicely
 * @array: array to sort
 * @min: min isx of partition
 * @max: max idx of partiton
 * @size: size of the array
 */

void q_sort(int *array, ssize_t min, ssize_t max, size_t size)
{
	ssize_t pivot;

	if (min < max)
	{
		pivot = partition(array, min, max, size);
		q_sort(array, min, pivot - 1, size);
		q_sort(array, pivot + 1, max, size);

	}
}
/**
 * partition - sorts arry of ints using quick sort lumuto style
 * @array: array to be sorted
 * @min: min value
 * @max: max value
 * @size: size of the array
 * Return: idx + 1
 */
size_t partition(int *array, ssize_t min, ssize_t max, size_t size)
{
	ssize_t i, j;
	int swap, pivot;

	pivot = array[max];
	i = min - 1;
	for (j = min; j < max; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[max] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[max];
		array[max] = swap;
		print_array(array, size);
	}
	return (i + 1);
}
